#!/bin/bash

# Simple fetch script, calling only default commands
# Made to work on Ubuntu 22.04.3 LTS
# Yoda ASCII from https://www.asciiart.eu/movies/star-wars

cr="\033[0;0m"  # reset
c1="\033[0;31m" # red
c2="\033[0;32m" # green
c3="\033[0;33m" # yellow
c4="\033[0;34m" # blue
c5="\033[0;35m" # magenta
c6="\033[0;36m" # cyan
c7="\033[0;37m" # white

echo
printf ". ~ May the force be with you ~ .\n"
printf " ${c2}__.-._   ${c1}      name | %s ${cr}\n" "$(whoami)@$(hostname)"
printf " ${c2}'-._\"${c5}7,  ${c2}    distro | %s ${cr}\n" "$(lsb_release -ds)"
printf " ${cr} /'.${c2}-${c5}c   ${c3}    uptime | %s ${cr}\n" "$(uptime -p)"
printf " ${cr} |  /${c5}T   ${c4}     shell | %s ${cr}\n" "$(echo $SHELL)"
printf " ${cr}_)_/${c2}L${c5}I   ${c5}  packages | %s ${cr}\n" "$(dpkg -l | grep -c '^ii')"
printf "${c3}~==-==~=  ${c6}   storage | %s ${cr}\n" "$(df -kh . --output='used,size,pcent' | tail -1 | xargs )"
echo
