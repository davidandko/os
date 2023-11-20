#!/bin/zsh

if [ $# -eq 0 || $# -gt 1 ]
then 
	echo "Invalid number of arguments, one argument expected!"
fi
if [ ! -d $1 ]
then
	mkdir $1
fi

files=(`find . -type f -exec ls -l {} \; | awk '$5>200 {print  " " $9}'`)

for file in ${files[@]}
do 
cp "$file" "$1"
done
