#!/bin/zsh

imenici=$(ls | grep '\.txt')


echo "$imenici"

kolku=$(ls | grep '\.txt' | wc -l)

if [ $kolku -gt 1 ]
then
prv=$(echo $imenici | head -1)
imenici=$(echo $imenici | cut -1)

for imenik in imenici:
do 
$(cat $imenik >> $prv)
done
imenici=$prv
fi
$(python3 ispit1_2019.py3 $imenici)

