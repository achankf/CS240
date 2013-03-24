#!/bin/bash


SEED=$( echo $RANDOM`date +%s` )
echo $SEED
#./normal.exe $* > out1
./bin.exe $SEED 2>/dev/null > out0
./normal.exe $SEED 2>/dev/null > out1
./seq.exe $SEED 2>/dev/null > out2
./exp.exe $SEED 2>/dev/null > out3

tail out0 out1 out2 out3
#./exp.exe $* > out3
