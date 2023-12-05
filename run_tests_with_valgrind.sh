#!/bin/bash

for file in bin/*;
do
    echo Running: "$file"
    echo =====================
    valgrind ./"$file"
    echo
done
