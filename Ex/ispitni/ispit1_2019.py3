#!/bin/python

import sys

if len(sys.argv) != 1:
	print('Invalid number of arguments, input one file name')
	
file = open(sys.argv[1],"r")

dictionary = {}

for line in file:
	dictionary[line.split(" ")[1]] = line.split(" ")[2]+" " +line.split(" ")[3] # [2] and [3] are the name and surname

file.close()

command = input("Please enter a command, USAGE: 1- Search by phone number; 2- Search by Name, 3- Print the contacts list\n")



if int(command) == 1:
	number = input("Please enter a phone number\n")
	if number in dictionary:
		print(dictionary[number])
	else:
		print("Number does not exist")
		
elif int(command) == 2:
	name = input("Please enter a Name\n")
	for key in dictionary:
		if dictionary[key] == str(name):
			print(key)
		else:
			print("Name does not exist")
		
elif int(command) == 3:
	for key in dictionary:
		print(key + " " +dictionary[key])
else:
	print("Command not found")
