#!/bin/zsh

if [ $# -gt 1 ]
then
echo "Too many arguments, this script allows one argument"
fi

extension_folder=$1

extension_files=`ls *.*` #gi zema site fajlovi so ekstenzija


if [ -d "$1" ]
then
	rm -r "$extension_folder"
fi
mkdir $extension_folder

for file in ${extension_files[*]}
do
	if [ -f "$file" ]
	then
		extension=`echo $file | sed 's/.*\.//'` #ja zema ekstenzijata od fajlot koj e momentalno iteriran
		if [ ! -d "${extension_folder}/${extension}" ] #ako ne postoi folder so toa ime kreiraj go
		then
		mkdir ${extension_folder}/${extension}
		fi
		cp ${file} ${extension_folder}/${extension}
	fi
done
