#!/bin/bash

GCC_OPTIONS='-g -ansi -pedantic -Wall'
TARGETS=("cc_decrypt" "cc_encrypt")

if [ "$#" -eq 1 ]; then
    if [ "$1" == "clean" ]; then
        for t in ${TARGETS[@]}; do
            echo "rm $t"
            /bin/rm $t
        done
        exit 0
    fi
    TARGET=$1
else
    echo "Usage: ./make.sh [target | clean]"
    exit -1
fi

echo "gcc $GCC_OPTIONS -o $TARGET $TARGET.c"
gcc $GCC_OPTIONS -o $TARGET $TARGET.c

exit 0