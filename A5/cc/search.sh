#!/bin/bash

#./normal.exe $* > out1
TEST=q1atest
IN=test5
./bin.exe -t 2>/dev/null <$TEST/$IN > out0
./normal.exe -t 2>/dev/null <$TEST/$IN > out1
./seq.exe -t 2>/dev/null <$TEST/$IN > out2
./exp.exe -t 2>/dev/null <$TEST/$IN > out3

tail out0 out1 out2 out3
#./exp.exe $* > out3
