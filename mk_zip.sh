#!/bin/bash

# Directory to search (default is current directory)
DIR="${1:-.}"

# Loop over matching directories
for folder in "$DIR"/Lab[0-9]*; do
    if [ -d "$folder/src" ]; then
        zipname="${folder%/}.zip"
        echo "Zipping cpp files from $folder/src -> $zipname"
        zip -j "$zipname" "$folder"/src/*.cpp 2>/dev/null
    fi
done

