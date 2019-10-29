#!/bin/bash

echo "Enter path to dir"
read $dir_path
cd $dir_path
ls -l | grep '^-'
