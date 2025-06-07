import sys


def hex_to_int(hexcode):
    return int(hexcode, 16)


if __name__ == "__main__":
    list_int_C = list(map(lambda x: hex_to_int(x[:-2]), sys.stdin.readlines()))

    for intn in list_int_C:
        print(intn)
