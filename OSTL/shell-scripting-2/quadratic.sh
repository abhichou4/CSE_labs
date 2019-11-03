#!/bin/bash

echo "Enter coeff"
read a
read b 
read c

d=$((b*b-4*a*c))
echo $d

if [ $d -lt 0 ]
then
exist=0
elif [ $d -gt 0 ]
then
exist=1
else 
exist=2
fi

case $exist in
0)
echo "does not exist"
;;
1)
echo "exist"
root1=`echo "scale=3;(-1*$b + sqrt($d)) / (2*$a)" | bc` 
root2=`echo "scale=3;(-1*$b - sqrt($d)) / (2*$a)" | bc`
;;
2)
echo "exist";;
esac
echo $root1 
echo $root2