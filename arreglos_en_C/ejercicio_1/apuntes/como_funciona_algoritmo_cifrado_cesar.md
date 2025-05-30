# Como funciona el algoritmo
- By: Jakepys

## Porque el formato `n:texto`?

El formato `"n:texto"` simplemente significa:
`<numero de desplazamiento>:<texto a cifrar>`


Se utilizar por claridad de entrada de datos, es como si tubiera dos partes.

- `n` -> un numero (ya sea 1, 26 etc.) que indica cuantas posiciones correr en el 
        cifrado cesar.

- `texto` -> todo lo que quieras cifar (como por ejemplo `"Jakepys"`)


### Ejemplo:
```
Entrada: 4:Jakepys 
```
Significa: cifrar la palabra "Jakepys" corriendo cada letra 4 posiciones.


## Entender un poco el codigo de C 

```c
char linea[209];
/*
Reserva espacio para la linea completa que el usuario escribira, Hasta 208 caracteres
+ '\0'.
*/
```

### `fgets(...)` y `strcspn`
Lee del teclado una linea hasta (208 caracteres) y luego con:
```c
int pos = strcspn(linea, "\n");
linea[pos] = '\0';

/*
Esto elimina el salto de linea \n que fgets agrega automaticamente al final de la entrada.
*/
```

### `procesar(cadena[])`

Esta funcion toma la linea `"n:texto"` y hace tres cosas principales:

1) Separa el numero del texto
```c

while(cadena[i] != ':') {
    desp_cad[i] = cadena[i];
    i++;
}

desp_cad[i] = '\0';
```
Esto toma el numero antes del `':'` y luego lo guarda como una cadena de caracteres
("3" por ejemplo). Luego
```c
int desp = atoi(desp_cad); // convierte el "3" a 3 entero
```

2) Extraer el texto despues del `:`

```c
i++; // saltar el ':'
while(cadena[i] != '\0') {
    texto[j] = cadena[i];
    i++; j++;
}
texto[i] = '\0';
```
Ahora `texto` contiene la parte del mensaje que debe cifrarse.


3) Cifrado Cesar
Ahora a tratar de entender el cifrado cesar xd.

```c

if(texto[j] >= 'A' && texto[j] <= 'Z') {
    texto[j] = ((texto[j] - 'A' + desp) % 26) + 'A';
}
```

Para entender mejor, dejo la tabla ASCII

```
-----------------------------------------------------
| Dec | Char | Dec | Char | Dec | Char | Dec | Char |
|-----|------|-----|------|-----|------|-----|------|
|  32 |   ␣  |  33 |   !  |  34 |   "  |  35 |   #  |
|  36 |   $  |  37 |   %  |  38 |   &  |  39 |   '  |
|  40 |   (  |  41 |   )  |  42 |   *  |  43 |   +  |
|  44 |   ,  |  45 |   -  |  46 |   .  |  47 |   /  |
|  48 |   0  |  49 |   1  |  50 |   2  |  51 |   3  |
|  52 |   4  |  53 |   5  |  54 |   6  |  55 |   7  |
|  56 |   8  |  57 |   9  |  58 |   :  |  59 |   ;  |
|  60 |   <  |  61 |   =  |  62 |   >  |  63 |   ?  |
|  64 |   @  |  65 |   A  |  66 |   B  |  67 |   C  |
|  68 |   D  |  69 |   E  |  70 |   F  |  71 |   G  |
|  72 |   H  |  73 |   I  |  74 |   J  |  75 |   K  |
|  76 |   L  |  77 |   M  |  78 |   N  |  79 |   O  |
|  80 |   P  |  81 |   Q  |  82 |   R  |  83 |   S  |
|  84 |   T  |  85 |   U  |  86 |   V  |  87 |   W  |
|  88 |   X  |  89 |   Y  |  90 |   Z  |  91 |   [  |
|  92 |   \\ |  93 |   ]  |  94 |   ^  |  95 |   _  |
|  96 |   `  |  97 |   a  |  98 |   b  |  99 |   c  |
| 100 |   d  | 101 |   e  | 102 |   f  | 103 |   g  |
| 104 |   h  | 105 |   i  | 106 |   j  | 107 |   k  |
| 108 |   l  | 109 |   m  | 110 |   n  | 111 |   o  |
| 112 |   p  | 113 |   q  | 114 |   r  | 115 |   s  |
| 116 |   t  | 117 |   u  | 118 |   v  | 119 |   w  |
| 120 |   x  | 121 |   y  | 122 |   z  | 123 |   {  |
| 124 |   |  | 125 |   }  | 126 |   ~  |     |      |
-----------------------------------------------------
```
Imagen por si es confuso el anterior.

![Tabla ASCII](./img/tabla_ascii.png)

### Pero que significa `texto[j] - 'A'`?

Esto convierte una letra en un indeice del alfabeto.

En ASCII:

```
-------------------------------
Letra          | Codigo ASCII 
               |
               |
A              |  65
-------------------------------
B              |  66
-------------------------------
...
-------------------------------
Z              |  90
-------------------------------
```

Entonces: 

```c
texto[j] - 'A'
```
- `"A" - 'A' = 0` -> primera letra
- `"B" - 'A' = 1` -> segunda letra 
- ... ETC 
- `"Z" - 'A' = 25` -? ultima letra 

Este valor (`0-25`) lo puedes usar como indice para aplicar *modulo 26*, que es el 
tamanio del alfabeto.

Luego se convierte otra vez a letra:
```c
((texto[j] - 'A' + desp) % 26) + 'A')
```

### Ejemplo (letra mayuscula)
Letra `D`
desplazamiento: `3`

```c 
texto[j] - 'A' = 68 - 65 = 3
3 + 3 = 6
6 % 26 = 6
6 + 'A' = 71 -> 'G'
```

Entonces `'D'` con desplazamiento `3` se convierte en `'G'`

### Ejemplo (letras minusculas)
Exactamente lo mismo, pero usando `'a'`
```c
((texto[j] - 'a' + desp) % 26) + 'a';
```
### Ejemplo (Numero)
Usar `'0'`
```c
((texto[j] - '0' + desp) % 10) + '0';
```
Solo hay 10 digitos: 0-9.



## Corte del programa con `#`
```c
while(strcmp(linea, "#") != 0)
```
Cuando el usuario escribe `"#"` el programa termina.


Para terminar la formula seria de esta forma:

`((caracter - base + desplazamiento) % rango) + base`

- `base`
    - `'A'` si mayúscula -> rango 26

    - `'a'` si minúscula -> rango 26

    - `'0'` si dígito -> rango 10



Tambien adjunto la imagen del profesor:

![Imagen Profe]("./img/algoritmodesplazamiento.png")
