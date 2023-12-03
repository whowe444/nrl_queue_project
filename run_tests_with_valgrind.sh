#!/bin/bash

TEST_BINARIES=`ls bin`

for file in ${TEST_BINARIES[@]}
do
    echo Running with valgrind: $file
    echo ===================== 
    valgrind ./bin/$file
    echo  
done
