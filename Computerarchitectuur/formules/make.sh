#!/bin/bash

latexmk

latexmk -pdf

latexmk -c

rm formules.dvi

if [ -n $i ]
then
	echo "no i yet"
	echo "Message for the commit"
	read commitmessage
else
	echo "i already defined"
	$commitmessage = $i
fi

git commit -am "$commitmessage"

git push
