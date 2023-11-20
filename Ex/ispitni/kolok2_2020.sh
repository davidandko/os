#!/bin/zsh

for file in $@:
do
exist=$(find . -name $file)
if [ -n $exist ]
then 
valid=$(cat $file | grep '[1-31]\-[1-12]\-[0-9][0-9][0-9][0-9]')

if [ -n $valid ]
then 
result=$(python3 kolok1_2020.py3 $exist)
d="${dat}_out"
result1=$(cat $d | awk '{print $1}' | uniq -u | wc -l)

echo "$dat $rez1"
fi
fi
done

