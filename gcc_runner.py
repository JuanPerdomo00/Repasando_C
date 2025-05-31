#!/usr/bin/python3
# -*- coding: utf-8 -*-
#
# gcc_runner.py - Compile and run C files with optional input
# Copyright (C) 2025  Jakepys
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

import argparse
import subprocess
import os
import sys


COMPILATION_OK = "💾 Compilation OK 💾\n"
ERR_COMPILATION = "🔴 Compilation error 🔴\n"


def gcc_command(file: str, name_bin: str) -> bool:
    proc = subprocess.Popen(
        ["/usr/bin/gcc", file, "-o", name_bin],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    _, stderr = proc.communicate()

    if proc.returncode != 0:
        print(ERR_COMPILATION)
        print(stderr.decode())
        return False

    print(COMPILATION_OK)
    return True


def run_binary(bin_path: str, entry: str | None = None):
    if entry:
        with open(entry, "r") as f:
            proc = subprocess.Popen([bin_path], stdin=f)
    else:
        proc = subprocess.Popen([bin_path])

    proc.wait()


def compile_and_run(file: str, name_file: str | None, entry: str | None):
    name_bin = name_file if name_file else file[:-2]
    bin_path = os.path.abspath(f"./{name_bin}")

    if gcc_command(file, name_bin):
        run_binary(bin_path, entry)


def main():
    parser = argparse.ArgumentParser(
        prog=os.path.basename(__file__), description="Compile and run a C file"
    )
    parser.add_argument("-f", "--file", required=True, help="C file name (e.g. main.c)")
    parser.add_argument("-n", "--namefile", help="Binary output name (e.g. program)")
    parser.add_argument(
        "-e",
        "--entry",
        help="Input file for the C program (e.g. input.txt)",
        default=None,
    )
    args = parser.parse_args()

    if args.entry and not args.entry.endswith(".txt"):
        print("❌ Only .txt files are allowed for input")
        sys.exit(1)

    compile_and_run(args.file, args.namefile, args.entry)


if __name__ == "__main__":
    main()
