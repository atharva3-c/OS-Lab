#!/bin/bash

for file in *; do

    if [ -f "$file" ]; then

        sed -i -e 's/^ex:/Example:/g' -e 's/\. ex:/\. Example:/g' "$file"
    fi
done





