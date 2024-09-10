#!/bin/bash


echo "Enter the folder path:"
read folder

echo "Enter the pattern to search for:"
read pattern


if [ ! -d "$folder" ]; then
    echo "$folder is not a valid directory."
    exit 1
fi


for file in "$folder"/*; do
    
    if [ -f "$file" ]; then
       
        if grep -q "$pattern" "$file"; then
           
            echo "$(basename "$file")"
        fi
    fi
done



