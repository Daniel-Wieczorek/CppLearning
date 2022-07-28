#!/bin/bash

# Variables:
COMPILE_COMMAND="g++ -Wall -std=c++14 -o main -g3"
RUN_DEFAULT_NAME="./main"

# Check input paramters
NUMBER_OF_PARAMETERS="${#}"
if [[ "${NUMBER_OF_PARAMETERS}" -lt 1 ]]
then
    echo "You must pass at least one argument"
    exit 1
fi

# create list of the files `.cpp`
OUTPUT_FILES=""
for FILE_NAME in ${@}
do 
    OUTPUT_FILES+=" ${FILE_NAME}"
done

# Clear current file (CLEAN BUILD)
DELETE_FILE=$(rm -f main)
eval ${DELETE_FILE}

# Create executable
FINAL_COMMAND="${COMPILE_COMMAND}${OUTPUT_FILES}"
eval ${FINAL_COMMAND}

# Run executable
eval $RUN_DEFAULT_NAME
