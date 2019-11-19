#!/bin/bash
Build=$(dpkg -s build-essential>/dev/null 2>&1; echo $?;)
Compiler=$(dpkg -s gcc-mips-linux-gnu>/dev/null 2>&1 ; echo $?;)
if [[ $Build -eq 0 ]] && [[ $Compiler -eq 0 ]]; then exit; fi
echo "Following packages are required, but are not present on the system: ";
if [[ $Build -ne 0 ]]; then echo "build-essential"; fi
if [[ $Compiler -ne 0 ]]; then echo "gcc-mips-linux-gnu"; fi
echo "Do you wish to install them? (y/n) "
read answer;

while true; do 
if [[ "$answer" == "y" ]];
then 
   if [[ $Build -ne 0 ]]; then sudo apt install build-essential; fi
    if [[ $Compiler -ne 0 ]]; then sudo apt install gcc-mips-linux-gnu; fi
    exit;
else if [[ "$answer" == "n" ]] ; then exit; 
else echo "(y/n)"; read answer; fi
fi

done
