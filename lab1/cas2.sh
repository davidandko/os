#!/bin/zsh


if [ $# -eq 0 ]; then
  file_to_find="naredbi.txt"
else
  file_to_find="$1"
fi


file_path=$(find . -type f -name "$file_to_find" -print -quit)

if [ -z "$file_path" ]; then
  echo "File not found: $file_to_find"
else

  if [ "$(dirname "$file_path")" != "." ]; then

    cp "$file_path" .
    echo "File '$file_to_find' copied to working directory."
  fi


  echo "Contents of '$file_to_find':"
  cat "$file_to_find"
fi

