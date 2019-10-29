#!/bin/bash
#Crete a dir in /home with 2 sub-dirs
mkdir ~/dir ~/dir/sub1 ~/dir/sub2
cd ~/dir/sub1

echo "Contents of file 1" > file1.txt
echo "Contents of file 2" > file2.txt
echo "Contents of file 3" > file3.txt 

cp file1.txt ../sub2
cd ../sub2
who | wc -l > file4.txt
ls | wc -l  >> file4.txt

