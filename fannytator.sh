#!/bin/bash

if [ ! -d tetrigen ] ; then
	git clone https://github.com/gcamerli/tetrigen.git 
	cd tetrigen && make
	mv tetrigen tetri_test
	cp tetri_test ../
	cd ../
fi

clear
while :; do 
	rm test.fillit 2> /dev/null
	echo "\033[0mVoulez-vous des pieces valides = 1, ou invalides = 2 ?"
	read answer
	if [ $answer -eq 3 ]; then
		break
	fi
	echo "Combien de tetriminos voulez vous ?"
	read nb
	if [ $answer -eq 1 ] ; then
		./tetri_test -v -f $nb
	elif [ $answer -eq 2 ] ; then
		./tetri_test -i -f $nb
	fi
	./fillit test.fillit
	echo "\n\n👯👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  👯  \n\n NOUVEAU TEST \n (Press 3 for quit)\n" 	
done

