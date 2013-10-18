#!/bin/bash

if [ ! $# -eq 1 ] ; then
	echo "Please give a svg file as param."
	exit 3
fi

if [ ! -e "$1" ] ; then
	echo "Please give a svg file as param."
	echo "Could not find '$1'."
	exit 3
fi

if ! 2>/dev/null 1>/dev/null which rsvg-convert ; then
	echo "rsvg-convert was not found."
	echo "Please install 'librsvg2-bin'."
	echo "When using apt-get, run: sudo apt-get install librsvg2-bin."
fi

IN="$1"
DIR=$(dirname "$IN")
FILE=$(basename "$IN")

PNGBASE=$(echo "$FILE" | sed 's|.svg||')
PNGBASE=$(echo "$PNGBASE" | sed 's|.SVG||')


SIZES='16;16
32;32
48;48
64;64
92;92
128;128
256;256'

IFS=$'\n'
for SIZE in $SIZES ; do
	PIX=$(echo "$SIZE" | cut -f1 -d';')
	ID=$(echo "$SIZE" | cut -f2 -d';')
	rsvg-convert -w $PIX -h $PIX -f png -o "$DIR/$PNGBASE-$IDx$ID.png" "$IN"
done
