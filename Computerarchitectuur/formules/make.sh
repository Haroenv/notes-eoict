#!/bin/bash

latexmk

latexmk -pdf

latexmk -c

rm formules.dvi

if [$i == ""]
then
	echo "Message for the commit"
	read commitmessage
else
	commitmessage = $i
fi

git commit -am "$commitmessage"

git push
