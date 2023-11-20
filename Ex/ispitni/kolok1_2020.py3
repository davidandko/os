#!/bin/python

import sys
import re


input_file=open(sys.argv[1],"r")
second=False
output_file=open(sys.argv[1]+"_out","a")
if len(sys.argv) >2:
	if sys.argv[2]==re.search("[0-31]-[1-12]-[1900-2023]",sys.argv[2]):
		second=True

#ke koristam re.findall()

for line in input_file:
	out=""
	search = re.findall("[0-31]-[1-12]-[1900-2023]",line)
	arr = line.split(" ")
	for date in search:
		out+=date
		if second == True:
			if date == sys.argv[2]:
				print(line)
		for notdate in arr:
			if notdate not in search:
				out+=notdate
		print(out)

