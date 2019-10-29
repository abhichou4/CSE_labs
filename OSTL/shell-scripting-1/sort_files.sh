#!/bin/bash

echo "Enter first filename"
read file1
echo "Enter second filename"
read file2
#cat $file1 $file2 > sorted.txt
sort -m -u $file1 $file2 > sorted.txt
