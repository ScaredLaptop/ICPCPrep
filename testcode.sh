#!/bin/bash

# List of directories to search
DIRS=("Codeforces" "Kattis" "Leetcode" "ProjectEuler" "OtherSite")

# Check if at least one argument was provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <filename_with_extension>"
    exit 1
fi

FILENAME=$1
FOUND=0
FILEPATH=""

# Check if the argument is a path or just a filename
if [[ "$FILENAME" =~ "/" ]]; then
    # Argument is a path
    FILEPATH="$FILENAME"
    FILENAME=$(basename "$FILENAME")
    DIR=$(dirname "$FILEPATH")
    if [ -f "$FILEPATH" ]; then
        FOUND=1
    fi
else
    # Argument is just a filename, search for the file in each directory
    for DIR in "${DIRS[@]}"; do
        if [ -f "$DIR/$FILENAME" ]; then
            FILEPATH="$DIR/$FILENAME"
            FOUND=1
            break
        fi
    done
fi

# If the file was not found in any directory, exit
if [ $FOUND -ne 1 ]; then
    echo "Error: File $FILENAME not found in any specified directory."
    exit 1
fi

# Compile the C++ file and capture any compilation errors
ulimit -s unlimited
g++ -O2 -Wall -Wextra -Wconversion -std=c++20 "$FILEPATH" -o "$DIR/$(basename "$FILENAME" .cpp)" 2> compilation_error.txt

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Errors:"
    cat compilation_error.txt
    exit 1
fi

EXECUTABLE="$DIR/$(basename "$FILENAME" .cpp)"

# Check if 'test' mode is enabled
if [ "$2" == "test" ]; then
    # Run in test mode: Input from stdin and output to stdout
    ./"$EXECUTABLE"
else
    # Run normally: Input from file and output to file
    ./"$EXECUTABLE" < input.txt > actual_output.txt

    # Compare actual output with expected output
    diff actual_output.txt expected_output.txt

    # Check the result of diff
    if [ $? -eq 0 ]; then
        echo "Success: No differences found."
    else
        echo "Differences found."
    fi
fi

# Delete the generated binary
rm "$EXECUTABLE"
