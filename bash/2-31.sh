#!/bin/env bash

count=1

while true
do
 ./2-3.sh &>>out.log
	if [[ $? -ne 0 ]]; then
	cat out.log
	echo "failed after $count times"
	break
	fi
	((count++))

done
