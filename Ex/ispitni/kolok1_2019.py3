#!/bin/python3

import sys
import re

if len(sys.argv) != 3:
	print('Usage: Pass 2 command line arguments.')
	sys.exit(1)

file1=open(sys.argv[1], "r")
file2=open(sys.argv[2], "r")
def match_attribute(el):
	if re.match(r'-+',el) != None:
		return True
	else:
		return False
	
	
dictionary = {}
for line in file1:
	dictionary[line.strip()] = ""



for line in file2:
	line_arr = line.strip().split()
	output=""
	for el in line_arr:
		if el in dictionary:
			output=el
		else:
			if match_attribute(el) == True:
				el_with_space=" "+str(el)
				output+=el_with_space
				# print(str(match_attribute(el)) + el)
			else: 
				break;
print(output)
	
	
		
file1.close()
file2.close()
