#!/bin/zsh

if [ $# -eq 0 ]
then
	found=`find . -name "naredbi.txt" | head -1`
	if [ -n $found ]
	then
	$(cp $dat .)
	actions=`find . "actions.txt"`
	fi
	if [ -n $actions ]
	then
	execute=$(python3 kolok1_2019.py3 naredbi.txt $actions)
	
	for command in $execute
	do
	tekst=$($command)
	if [ -z $tekst ]
	then 
	echo "OK $command"
	else
	echo "ERROR $command"
	fi
	done
	fi
	fi
	else
	execute=$(python3 kolok1_2019.py3 naredbi.txt $1)
	for command in $execute
	do
	tekst=$($command)
	if [ -z $tekst ]
	then 
	echo "OK $command"
	else
	echo "ERROR $command"
	fi
	done
	fi
	
	

