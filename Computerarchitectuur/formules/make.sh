#!/bin/bash

latexmk -c formules.tex

#rm formules.dvi

read commitmessage

git commit -am "commitmessage"

git push
