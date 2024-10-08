#!/bin/bash

# Check if at least one argument is provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 file1 [file2 ... fileN]"
    exit 1
fi

# Iterate over each file provided as an argument
for file in "$@"; do
    # Check if the file exists
    if [ -f "$file" ]; then
        # Remove the file
        rm "$file"
        echo "$file has been deleted."
    else
        echo "$file does not exist."
    fi
done

