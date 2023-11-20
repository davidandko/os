#!/bin/zsh

last | awk '{print $1 " " $3 " " $9}' | grep -e 'Sat' -e 'Sun' | grep '([0-9][2-9].*' | awk '{print $1}' | uniq -u
