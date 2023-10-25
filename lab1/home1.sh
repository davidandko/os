#!/bin/zsh

death= pgrep $1

kill -9 $death

