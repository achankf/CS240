#!/bin/bash

i=0
while true; do
	let "i=i+1"
	./a04q2cdriver.exe >/dev/null 2>&1
	[ $? -eq 1 ] && break
	echo $i
done
