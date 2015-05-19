# Vind de volgorde

bv: 1 - 4 - 5 - 7 - 10 - 5 - 0 - 3 - 1

# zet in Karnaugh

1. tip: in volgorde
2. schuif eentje op (in de volgorde dat hierboven staat) naar boven

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

3. sorteer, voeg overgebleven toe als `X`

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

4. Zet om naar functie m.b.v. Karnaugh-kaart
	* gebruik [hulptabel](tabel.pdf)

# Maak schema

1. Kijk welk soort Latches je moet gebruiken
	* TODO: welke soorten bestaan er, hoe te bepalen welke je wil gebruiken

2. Verbind
	* Q.. met J/K.. volgens functie
	* Klok naar een functiegenerator (1MHz?)
	* Vcc ==> +5V
	* GND / ongebruikte ingangen ==> 0V
	* TODO: SET/CLR volgens soort latch

3. Uitgangen gewoon aan LEDs

4. Uitgangen naar LED display
	* Encoding?