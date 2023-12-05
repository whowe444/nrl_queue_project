#!/bin/bash

for file in bin/*;
do
    echo Running: "$file"
    echo =====================
    valgrind --max-stackframe=8000008 ./"$file"
    echo
done
