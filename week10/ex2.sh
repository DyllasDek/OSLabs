#!/bin/bash
rm -r week01 week10
mkdir week01
cd week01
echo '23' > file.txt
cd ../
mkdir week10
cd week10
link ../week01/file.txt _ex2.txt
inod=$(ls -i ../week01/file.txt|cut -c 1-6)
find ../ -inum $inod >> ex2.txt
find ../ -inum $inod -exec rm {} \; >> ex2.txt
cd ../
