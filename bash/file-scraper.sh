#!/bin/bash

### Author:	youngtrashbag
### Date:	23.07.2020
### desc.:	this is intened to scrape images.
###					I've wanted to make an extension with this idea for the longest time,
###					but never got to it. so here you go. Have fun !
### NOTE: this only works if the files are numbered in order.


$FROM		# range start
$TO		# range end

$ADDRESS	# the website, where the files are stored
$EXTENSION	# the file extension (without the dot)

$FOLDER		# the folder where the downloaded files should be stored

$FROM=0
$TO=10
$ADDRESS="https://1secondpainting.com/wp-content/uploads/2020/07/"		# with range 1 to 10 this will exclusively download anime/manga pictures and not ai pictures
$FOLDER="1-sec-painting"
$EXTENSION="png"


if [ ! -d "./$FOLDER" ]
then
	mkdir ./$FOLDER
fi

for $i in {$FROM .. $TO}
do
	curl "$ADDRESS$i.$EXTENSION" > ./$FOLDER/$i.$EXTENSION
done
