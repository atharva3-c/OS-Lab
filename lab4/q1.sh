#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 source_file destination_file"
    exit 1
fi

# Get the source and destination file names from the command-line arguments
source_file="$1"
destination_file="$2"

# Check if the source file exists
if [ ! -f "$source_file" ]; then
    echo "Error: Source file '$source_file' does not exist."
    exit 1
fi

# Copy the source file to the destination file
cp "$source_file" "$destination_file"

# Verify if the copy operation was successful
if [ $? -eq 0 ]; then
    echo "File '$source_file' has been successfully copied to '$destination_file'."
else
    echo "Error: Failed to copy '$source_file' to '$destination_file'."
fi

