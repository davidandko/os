#!/bin/python3 

if len(sys.argv) != 3:
	print("Incorrect number of arguments. \n USAGE: Enter two file names)
else:
file1=open(sys.argv[1],"r")
file2=open(sys.argv[2],"r")
