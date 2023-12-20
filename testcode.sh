#!/bin/bash

# Check if at least one argument was provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <filename_without_extension> [test]"
    exit 1
fi

FILENAME=$1

# Compile the C++ file and capture any compilation errors
ulimit -s unlimited
g++ -O2 -Wall -Wextra -Wconversion -std=c++20 "Codeforces/$FILENAME.cpp" -o "Codeforces/$FILENAME" 2> compilation_error.txt

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Errors:"
    cat compilation_error.txt
    exit 1
fi

# Check if 'test' mode is enabled
if [ "$2" == "test" ]; then
    # Run in test mode: Input from stdin and output to stdout
    ./Codeforces/$FILENAME
else
    # Run normally: Input from file and output to file
    ./Codeforces/$FILENAME < input.txt > actual_output.txt

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
rm "Codeforces/$FILENAME"