#!/bin/zsh

if [  $# -eq 0 ]
then
echo "No arguments passed"
fi

array_of_arguments=($@)

echo "Passed arguments:"
echo "$array_of_arguments"

	for arg in  ${array_of_arguments[*]}
	do
		if [ -f "$arg" ]
		then
			new_name=`echo "$arg1" | sed 's/\..*//'`
			echo "Renaming file $arg to $new_name.txt"
			mv $arg $new_name.txt
		elif [ -d "$arg" ] 
		then
			number_of_lines=`ls -l $arg | wc -l`
			echo "Number of lines: $number_of_lines"
		fi		
	
	
	done
