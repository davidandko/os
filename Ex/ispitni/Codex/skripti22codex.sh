#!/bin/zsh


if [ -f "execute.txt" ]
then
	rm "execute.txt"
fi

files=(`find $HOME -type f -exec ls -l {} \; | awk '{print $1 " " $9}' | grep '.*x@'` | awk '{print $2}')

for file in ${files[@]}
do
absolute_path=`find / -name $file`
echo "Fajlot $file se naogja vo folderot $absolute_path" >> execute.txt
done

cat execute.txt









