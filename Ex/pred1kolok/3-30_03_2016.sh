#!/bin/zsh

shell_scripts=$(grep -rl '^#!/bin/zsh' . | grep -E '\.sh$')

stat_file="stat_shell.txt"

if[ ! -e $stat_file ]
then
touch "$stat_file"
fi

output_file="izlez.txt"

if[ ! -e "$output_file" ]
then
touch "$output_file"
fi

for script in $shell_scripts
do 
script_name=$(basename "$script")
script_path=$(realpath "$script")

num_variables=$(grep -c '^[[:space:]]*[a-zA-Z_][a-zA-Z0-9_]*=' "$script")
num_branches=$(grep -c '^[[:space:]]*(if|elif|else|while|for|switch|case)' "$script")

complexity$((num_variables + num_branches))

echo "$script_name $script_path $num_variables $num_branches
$complexity" >>"$stat_file"

bash "$script" >> "$output_file"