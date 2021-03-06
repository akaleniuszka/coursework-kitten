#!/bin/bash
# Author: Wolfgang C. Strack
# CIS18C Lab5-6 module 6 script
usage="Usage: $0 filename"

if [ $# -ne 1 ]; then # less than 1 or greater than 2 args
	echo $usage
	exit 1
fi

filename=$1
if [ ! -e "$filename" -o ! -f "$filename" ]; then
	echo $filename does not exist
	exit 2
fi

# store all lines of file into array
IFS=$'\n'
lines=(`cat $filename`)

usageError=0
argsError=0
noError=0

for line in ${lines[@]}; do
	# use of eval needed to interpret separate arguments in $line
	eval ./module5script.bash $line &> /dev/null
	exitStatus=$?
	if (( exitStatus == 0 )); then
		noErrorArr[(( noError++ ))]=$line
	elif (( exitStatus == 1 )); then
		usageErrorArr[(( usageError++ ))]=$line
	else
		argsErrorArr[(( argsError++ ))]=$line
	fi
done

# print statistics
echo "${#usageErrorArr[@]} cases with command line errors:"
for error in ${usageErrorArr[@]}; do echo -e "\t$error"; done # print separate lines, each tabbed once
echo "${#argsErrorArr[@]} cases with invalid argument errors:"
for error in ${argsErrorArr[@]}; do echo -e "\t$error"; done
echo "${#noErrorArr[@]} cases with no error:"
for error in ${noErrorArr[@]}; do echo -e "\t$error"; done
