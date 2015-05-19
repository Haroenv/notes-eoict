# Vind de volgorde

bv: 1 - 4 - 5 - 7 - 10 - 5 - 0 - 3 - 1

# zet in Karnaugh

1. tip: in volgorde
1. schuif eentje op (in de volgorde dat hierboven staat) naar boven

	```
	1 ==> 4
	4 ==> 5
	5 ==> 7
	7 ==> 10
	10 ==> 5 + 8 = 13
	5 + 8 = 13 ==> 0
	0 ==> 3
	3 ==> 1
	```

1. sorteer, voeg overgebleven toe als `X`

	```
	0 ==> 3
	1 ==> 4
	3 ==> 1
	4 ==> 5
	5 ==> 7
	6 ==> X
	7 ==> 10
	8 ==> X
	9 ==> X
	10 ==> 5 + 8 = 13
	11 ==> X
	12 ==> X
	5 + 8 = 13 ==> 0
	14 ==> X
	...
	```

1. Zet om naar functie m.b.v. Karnaugh-kaart
	* gebruik [hulptabel](tabel.pdf)