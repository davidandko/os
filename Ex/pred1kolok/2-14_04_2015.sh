#!/bin/zsh

prva=$(find / -type -f -name naredbi.txt | head -1)
vtora=$(find / -type -f -name vlez.txt | head -1)

if [ -n $prva]
then 
 rm $prva

fi

if [ -n $vtora]
then 
rm $vtora
fi

touch naredbi.txt
touch vlez.txt

naredbi=$(python3 nekojaskripta.py3)

echo $naredbi >> izlez.txt

ls /usr/bin | tail -n -10 > naredbi1.txt

sed -e 's/$/ --help/' naredbi1.txt > vlez1.txt

echo "$(python3 nekojaskripta.py3 naredbi1.txt vlez1.txt)"



