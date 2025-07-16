#!/bin/bash

search_dir="${1:-.}"
output_file="small_files.txt"

# Store absolute path to the output file so we can exclude it
output_path="$(realpath "$output_file")"

# Find files under 2KB, skip the output file itself, and print relative paths
find "$search_dir" -type f -size -2k ! -path "$output_path" -exec realpath --relative-to="$search_dir" {} \; > "$output_file"
