#!/bin/bash
echo "Directories:"
ls -l | grep '^d'
echo "Files:"
ls -l | grep '^-'
