#!/usr/bin/env bash

if [ -n "$1" ]; then
    NAME="$1"
else
    NAME="you"
fi

echo "One for $NAME, one for me."
