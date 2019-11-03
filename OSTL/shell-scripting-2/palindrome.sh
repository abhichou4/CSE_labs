#!/bin/bash

echo "Enter a string"
read str 

i=0
len=$((`echo $str | wc -c`-1))
flag="true"

for((i=1;i<=len;i++))
do
	l1=`echo $str | cut -c $i`
	l2=`echo $str | cut -c $((len+1-i))`
	if [ $l1 != $l2 ]
	then 
		flag="false"
	fi
done

if [[ $flag == "true" ]]
then
	echo "String is a Palindrome"
else 
	echo "String is not a Palindrome"
fi