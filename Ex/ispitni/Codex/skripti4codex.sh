#!/bin/zsh

last | awk '{print $3}' | grep '31\.11\..*\..*' | uniq
