#!/bin/python

import sys
import os

argList = sys.argv[1:]

iterated= []

for el in argList:
	f=open(el,"r",newline='.')
	print(f.readline())
	f.close()
