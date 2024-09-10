#!/bin/bash


echo "Enter the file extension (e.g., .txt):"
read extension

echo "Enter the target folder:"
read target_folder

if [ ! -d "$target_folder" ]; then
    echo "$target_folder does not exist. Creating it now."
    mkdir -p "$target_folder"
fi

for file in *"$extension"; do
    if [ -f "$file" ]; then
        cp "$file" "$target_folder/"
    fi
done

echo "Files with the extension $extension have been copied to $target_folder."

