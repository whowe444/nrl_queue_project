#!/bin/bash
TEST_BINARIES=`ls bin`

for file in ${TEST_BINARIES[@]}
do
    echo Running: $file
    echo =====================
    ./bin/$file
    echo
done
