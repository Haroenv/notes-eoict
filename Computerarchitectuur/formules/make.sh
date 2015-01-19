#!/bin/bash

latexmk

latexmk -pdf

latexmk -c

#rm formules.dvi
echo "Message for the commit"
read commitmessage

git commit -am "$commitmessage"

git push
