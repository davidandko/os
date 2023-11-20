#!/bin/zsh

prva=$(find / type -f -name naredbi.txt)
vtora=$(find / type -f -name vlez.txt)

if [ -n prva ]
then
cp . $prva
fi
if [ -n vtora]
then 
cp . $vtora
fi

naredbi=$(python3 nekojaskripta.py3)

echo "$naredbi" >> izlez.txt

# bonusot: poslednite 10 naredbi od /usr/bin se smestuvaat vo naredbi1.txt so nastavka --help

ls /usr/bin | tail -n -10 > naredbi1.txt


sed -e 's/$/ --help/' naredbi1.txt > vlez1.txt

prethodna_output=$(python3 nekojaskripta.py3 naredbi1.txt vlez1.txt)

echo $prethodna_output