#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 -option input_file"
    echo "Options:"
    echo "  -linecount   Count the number of lines in the file"
    echo "  -wordcount   Count the number of words in the file"
    echo "  -charcount   Count the number of characters in the file"
    exit 1
fi

# Extract the option and input file from command-line arguments
option="$1"
input_file="$2"

# Check if the input file exists
if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' does not exist."
    exit 1
fi

# Perform the operation based on the option provided
case "$option" in
    -linecount)
        # Count the number of lines
        wc -l < "$input_file"
        ;;
    -wordcount)
        # Count the number of words
        wc -w < "$input_file"
        ;;
    -charcount)
        # Count the number of characters
        wc -c < "$input_file"
        ;;
    *)
        echo "Error: Invalid option '$option'."
        echo "Valid options are -linecount, -wordcount, -charcount."
        exit 1
        ;;
esac

