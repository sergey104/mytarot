#!/bin/bash
FILES=/home/fil/Projects/www.psychic-revelation.com/reference/q_t/tarot/tarot_cards/*
for f in $FILES
do
  #echo "Processing $f file..."
  # take action on each file. $f store current file name
  /home/fil/Projects/html_parser/test $f
  
done
