#!/bin/bash

function rename_files_in_directory {
    for file in $1/*; do
        if [ -d "$file" ]; then
            rename_files_in_directory "$file"
        else
            baseName=$(basename "$file")
            extension="${file##*.}"

            case "$baseName" in
            sionel.*) mv "$file" "${file/sionel/최은우}" ;;
            asd0236.*) mv "$file" "${file/asd0236/박상훈}" ;;
            junki1912.*) mv "$file" "${file/junki1912/김준기}" ;;
            seongheonjeong.*) mv "$file" "${file/seongheonjeong/정성헌}" ;;
            yundoun.*) mv "$file" "${file/yundoun/윤도운}" ;;
            esac
        fi
    done
}

rename_files_in_directory "."
