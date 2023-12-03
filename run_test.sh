#!/bin/bash

TEST_BINARIES=`ls bin`

for file in ${TEST_BINARIES[@]}
do 
    exec ./bin/$file
done
