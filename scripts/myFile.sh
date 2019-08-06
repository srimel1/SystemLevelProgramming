#!/usr/bin/env bash
if [ "$#" -ne 3  ]; then
    echo "usage: myFile <filename> <startline> <endline>"
    exit 1
fi
# get number of lines
numLines=$(cat $1 | wc -l)
echo "Total number of lines: $numLines"
# check to see if there are  enough line in file to write
if (( $3 > $numLines )); then
    echo "Lines do not exist in file"
    exit 1
fi
head -$3 $1 | tail -n $2 > newFile



