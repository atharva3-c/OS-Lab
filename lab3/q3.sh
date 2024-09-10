#!/bin/bash


find . -type f -name "*.txt" | while read -r file; do
   
    newfile="${file%.txt}.text"
   
    mv "$file" "$newfile"
done

