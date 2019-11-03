#!/bin/bash

echo "Individually Quoted List:"
echo $@
echo "Number of positional params"
echo $#
echo "p id of last background command:"
echo $!
echo "Name of shell script:"
echo $0
echo "Process id of of shell script:"
echo $$
echo "first param"
echo $1
echo "second param"
echo $2
echo "List of all params in single variable"
echo $*
