#!/bin/bash


if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments required - <writefile> <writestr>"
    exit 1
fi


writefile=$1
writestr=$2


writedir=$(dirname "$writefile")


mkdir -p "$writedir" 2>/dev/null
if [ $? -ne 0 ]; then
    echo "Error: Could not create directory '$writedir'"
    exit 1
fi


echo "$writestr" > "$writefile" 2>/dev/null
if [ $? -ne 0 ]; then
    echo "Error: Could not create or write to file '$writefile'"
    exit 1
fi

echo "File '$writefile' created successfully with content: $writestr"
