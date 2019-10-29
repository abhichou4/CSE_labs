#!/bin/bash 
echo "Enter filename" 
read filename
echo "Enter text (Press [CTRL-D] when done)"
cat > $filename
