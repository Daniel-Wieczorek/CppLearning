#!/bin/bash

# Variables:
COMPILE_COMMAND="g++ -Wall -std=c++14 -o main -g"
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

# Create executable
FINAL_COMMAND="${COMPILE_COMMAND}${OUTPUT_FILES}"
eval ${FINAL_COMMAND}

if [ "${?}" -ne 0 ]
then
    echo 'Compilation problem'
    exit 1
fi

# Run executable
eval $RUN_DEFAULT_NAME
