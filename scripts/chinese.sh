#!/bin/bash

## cmdline argument is e.g. "2003-10-22"
DATE=$1

### extract day, month and year into separate variables
MONTHDAY=${DATE#*-}

YEAR=${DATE%%-*}
MONTH=${MONTHDAY%%-*}
DAY=${MONTHDAY#*-}

# an array to look up th month-names
# since month-numbers start with 1, the first element in the array is invalid.
set -A monthnames invalid Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec

## perform the lookup
MONTHNAME=${monthnames[${MONTH}]}

## display "<Month> <DAY>"
echo ${MONTHNAME} ${DAY}
