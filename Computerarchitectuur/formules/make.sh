#!/bin/bash

latexmk

latexmk -c -pdf

#rm formules.dvi
echo "Message for the commit"
read commitmessage

git commit -am "$commitmessage"

git push
