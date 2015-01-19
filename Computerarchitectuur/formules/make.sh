#!/bin/bash

latexmk -c formules.tex

#rm formules.dvi
echo "Message for the commit"
read commitmessage

git commit -am "$commitmessage"

git push
