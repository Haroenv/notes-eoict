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
	10 ==> 5 + 2^{aantal flipflops} = 13
	11 ==> X
	12 ==> X
	5 + 2^{aantal flipflops} = 13 ==> 0
	14 ==> X
	...
	```

4. exitatietabel

	| Qi | Qi+1 | J | K |
	|----|------|---|---|
	| 0  | 0    | 0 | X |
	| 0  | 1    | 1 | X |
	| 1  | 0    | X | 1 |
	| 1  | 1    | X | 0 |

5. Zet om naar functie m.b.v. Karnaugh-kaart
	* gebruik [hulptabel](tabel.pdf)
	* kijk wat Q1... is

# Maak schema

1. Kijk welk soort Latches je moet gebruiken
	* MM74HC112 voor J/K Flip-Flop
	* TODO: welke soorten bestaan er, hoe te bepalen welke je wil gebruiken

2. Verbind
	* Q.. met J/K.. volgens functie
	* Klok naar een functiegenerator (1MHz?)
	* Vcc ==> +5V
	* GND / ongebruikte ingangen ==> 0V
	* SET/CLR volgens soort latch
		* kijk naar eerste staat
		* zet bij die die 1 moeten zijn CLRB op 5V
		* bij die die 0 zijn: PREB op 5V
		* alle andere door een schakelaar naar 5V

3. Uitgangen gewoon aan LEDs

4. Uitgangen naar LED display
	* 4 bit BCD ==> 7 segmentdisplay
	* SN74LS47