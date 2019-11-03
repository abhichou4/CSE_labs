#!/bin/bash

echo "Enter String"
read string 
echo "Enter Sub-string"
read sub
if [[ $string = *$sub* ]];
then
echo "is sub-string"
else
echo "not sub-string"
fi
