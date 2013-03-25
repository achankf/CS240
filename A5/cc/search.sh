#!/bin/bash

#./normal.exe $* > out1
TEST=q1atest
IN=$1
./bin.exe -t 2>/dev/null <$TEST/$IN > bin.out
./normal.exe -t 2>/dev/null <$TEST/$IN > normal.out
./seq.exe -t 2>/dev/null <$TEST/$IN > seq.out
./exp.exe -t 2>/dev/null <$TEST/$IN > exp.out

tail *.out
