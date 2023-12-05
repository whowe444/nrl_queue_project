#!/bin/bash

for file in bin/*;
do
    echo Running: "$file"
    echo =====================
    ./"$file"
    echo
done
