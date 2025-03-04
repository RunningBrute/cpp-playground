#!/bin/bash

# check if file name exist
if [ -z "$1" ]; then
    echo "Usage: ./run.sh path/to/file.cpp"
        exit 1
        fi

        FILE=$1
        OUTPUT="output"

        g++ -std=c++17 -Wall -Wextra -o $OUTPUT $FILE

        # check if compilation success
        if [ $? -eq 0 ]; then
            echo "Compilation success! Run program..."
                ./output
                else
                    echo "Compilation Error!"
                    fi
                    