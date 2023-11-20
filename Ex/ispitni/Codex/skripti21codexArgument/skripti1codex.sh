#!/bin/zsh

folder1=$1
folder2=$2

files1=(`ls $folder1`)
files2=(`ls $folder2`)
echo "$1 $2"

for name1 in ${files1[*]}
	do
	if [ -f "$folder1/$name1" ]
	then
	content1=`cat $folder1/$name1`
	for name2 in ${files2[*]}
	do
	if [ -f  "$folder2/$name2" ]
	then
	content2=`cat $folder2/$name2`
	if [ $content1 = $content2 ]
	then
	echo "Found a match"
	echo "$content1"
	fi 
	fi 
	done
	fi
	done
