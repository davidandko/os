#!/bin/python

import sys

argList=list(sys.argv[1:])		

def swapPositions(list):
	for i in range(len(argList) // 2):
		list[i], list[-(i+1)] = list[-(i+1)], list[i]
   
	return list
 

if (len(argList) < 2):
	print('Not enough arguments')
else:
		argList = swapPositions(argList)

			
print(argList)
		
