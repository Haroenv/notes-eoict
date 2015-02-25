# µControllers - Les 2
25 februari 2015

Computertechnologie 2

# Assembler vs machinetaal

`addlw` = assembler

`24000` = machinetaal

# assembler vs hogere talen

Assembler is niet cross-platform (zelfs afhankelijk van processor tot processor)

Assembler kan hardwarematig aan alle geheugenplaatsen

# instructios

## Data verplaatsen

verschillende soorten verplaatsen en kopieren

`movlw` = *mov*e (kopieer) *l*iteral (constante) naar *w*reg (= in processor zelf)

`movwf` = *mov* (kopieer) *w*reg naar *f*ilesystem

`movlf D'5',getal` literal kan niet rechtstreeks naar filesystem

`movff getal1,LATD` juist

`movwl D'5'` je kan het niet direct naar een constante opslaan

`movf getal2` movf verwacht 2 argumenten

```assembly
movlw D'12'			# 12 decimaal zit nu in wreg
movwf getal1		# getal1 in filesystem is nu 12
movlw H'12'			# 18 zit nu in wreg
movwf getal2		# getal2 zit nu in filesystem met waarde 18
clrf getal2			# getal2 bestaat niet meer
movf getal2,W		# niets wordt gekopieerd
```

## Wiskundige instructies

## Logische instructies