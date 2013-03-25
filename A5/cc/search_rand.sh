#!/bin/bash


SEED=$( echo $RANDOM`date +%s` )
echo $SEED
#./normal.exe $* > out1
./bin.exe $SEED 2>/dev/null > bin.out
./normal.exe $SEED 2>/dev/null > normal.out
./seq.exe $SEED 2>/dev/null > seq.out
./exp.exe $SEED 2>/dev/null > exp.out

tail *.out
