#!/bin/bash

# Check if at least two arguments are provided
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 input_file pattern1 [pattern2 ... patternN]"
    exit 1
fi

# Extract the input file and patterns from command-line arguments
input_file="$1"
shift
patterns=("$@")

# Function to search patterns in the file
search_patterns() {
    for pattern in "${patterns[@]}"; do
        echo "Lines containing pattern '$pattern':"
        grep "$pattern" "$input_file"
        echo
    done
}

# Function to delete occurrences of patterns from the file
delete_patterns() {
    local temp_file="tempfile.txt"

    # Backup the original file
    cp "$input_file" "$temp_file"

    for pattern in "${patterns[@]}"; do
        sed -i "/$pattern/d" "$temp_file"
    done

    # Replace the original file with the modified file
    mv "$temp_file" "$input_file"
    echo "All occurrences of patterns have been deleted."
}

# Menu loop
while true; do
    echo "Menu:"
    echo "1. Search patterns in the file"
    echo "2. Delete occurrences of patterns from the file"
    echo "3. Exit"
    read -p "Choose an option [1-3]: " choice

    case "$choice" in
        1)
            search_patterns
            ;;
        2)
            delete_patterns
            ;;
        3)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid option. Please select a valid option."
            ;;
    esac
done

