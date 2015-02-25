# µControllers - Les 2
25 februari 2015

Computertechnologie 2

# Assembler vs machinetaal

`addlw` = assembler

`24000` = machinetaal

# assembler vs hogere talen

Assembler is niet cross-platform (zelfs afhankelijk van processor tot processor)

Assembler kan hardwarematig aan alle geheugenplaatsen

# Instructies

## Data verplaatsen

verschillende soorten verplaatsen en kopieren

`movlw` = *mov*e (kopieer) *l*iteral (constante) naar *w*reg (= in processor zelf)

`movwf` = *mov* (kopieer) *w*reg naar *f*ilesystem

`movlf D'5',getal` literal kan niet rechtstreeks naar filesystem

`movff getal1,LATD` juist

`movwl D'5'` je kan het niet direct naar een constante opslaan

`movf getal2` movf verwacht 2 argumenten

```asm
movlw D'12'			# 12d = 0x0C zit nu in wreg
movwf getal1		# getal1 in filesystem is nu 12d = 0x0C
movlw H'12'			# 18d = 0x12 zit nu in wreg
movwf getal2		# getal2 zit nu in filesystem met waarde 18d = 0x12
clrf getal2			# getal2 = 0d = 0x00
movf getal2,W		# wreg is 0d = 0x00
```

## Wiskundige instructies

### Optelling

`addlw` = *add* (tel op) een literal (constante) bij *w*reg

`addwf` = *add* iets uit *w*reg naar *f*ilesystem

als optelling te groot wordt, is er een *C*arry flag die bijhoudt zoals bij manuele optelling

### Flags

C: als een optelling groter is dan 1 byte

Z: als een bewerking uitkomst 0 heeft

N: als het resultaat negatief is

### Aftrekking

`sublw` = wreg = literal - wreg

`subwf` = wreg = eersteArgument - wreg

```asm
movlw 0x23			# wreg = 0x23
addlw 0x3F			# wreg = 0x23 + 0x3F = 0x62
movwf getal1		# getal1 = 0x62
movlw 0x12			# wreg = 0x23
subwf getal1,w		# wreg = 0x62 - 0x23 = 0x3F
```

## Logische instructies