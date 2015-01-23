#!/bin/bash

latexmk

latexmk -pdf

latexmk -c

rm formules.dvi

if [ "$1" ]
then
	echo "Commit message already defined"
	commitmessage=$1
else
	echo "Enter commit message"
	read commitmessage
fi

git commit -am "$commitmessage"

if [ "$2" ]
then 
	echo "Not pushed"
else
	git push
fi
