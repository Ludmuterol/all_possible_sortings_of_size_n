#!/bin/bash

#prints out all possible sets of numbers from 1 to max with max elements without repeating values
max=7

getstuff3(){
  local str="$2"
  if [[ $1 -eq $max ]]; then
    echo "$2x"
  else
    for ((i = 1; i <= $max; i++)); do
      if [[ "$str" != *"$i"* ]]; then
        echo $(getstuff3 $(($1 + 1)) "$str $i")
      fi
    done
    
  fi
}
echo $(getstuff3 0 "") | sed 's/x/\n/g'
