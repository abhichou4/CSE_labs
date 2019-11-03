#!/bin/bash

echo Enter Number
read num

n=num
sum=0

while [ $n != 0 ]
do 
	sum=$(( sum+ (n%10)**3 ))
	n=$(( n/10 ))
done

if [ $sum -eq $num ]
then
	echo Armstrong 
else 
	echo Not 
fi