#!/bin/bash
mkdir tmp
cd tmp
touch file1 file2
link file1 link1
cd ../
gcc ex4.c -o ex4
./ex4
