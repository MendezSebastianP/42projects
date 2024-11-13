#!/bin/bash

# Specify the source and target directories
SOURCE_DIR="."  # Change to the directory containing your .c files if different
TARGET_DIR="."

# Create the target directory if it doesn't exist
mkdir -p "$TARGET_DIR"

# Loop through each .c file in the source directory
for file in "$SOURCE_DIR"/*.c; do
    # Get the base name of the file (e.g., "file.c" from "/path/to/file.c")
    filename=$(basename "$file")

    # Format the file and save it in the target directory with the same name
    c_formatter_42 < "$file" > "$TARGET_DIR/$filename"

    echo "Formatted $file and saved as $TARGET_DIR/$filename"
done

echo "All files have been formatted and saved in $TARGET_DIR"
