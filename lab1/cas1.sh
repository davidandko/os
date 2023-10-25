#!/bin/zsh

if [ $# -eq 0 ]; then
	echo "Error! No input arguments.\n Please specify a filepath"
else
	awk  '{print "<"$1,$2">" " "($3+$4+$5)/3 }' $1
fi
