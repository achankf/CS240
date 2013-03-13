#!/bin/bash

while true; do
	./a04q2cdriver.exe 2> out
	[ $? -eq 1 ] && break
done
