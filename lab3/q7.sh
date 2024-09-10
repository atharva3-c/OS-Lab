#!/bin/bash

echo "Enter the file name:"
read file

if [ ! -f "$file" ]; then
    echo "$file does not exist."
    exit 1
fi

sed -i '1~2d' "$file"

echo "Even-numbered lines have been deleted from $file."

