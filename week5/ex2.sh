#!/bin/bash
echo 0 >> test.txt
for ((i=0;i<100;i++))
do
LAST=`tail -1 test.txt`
NEXT=`expr 1 + ${LAST}`
echo "$NEXT" >> test.txt
done
