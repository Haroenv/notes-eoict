;******************************************************************************
;	Dit bestand is een basis template om assembler code te schrijven voor de 
; 	PIC18F4550. Het is speciaal aangepast om gebruik te kunnen maken van de
; 	HID bootloader en toch simulatie toe te laten
;
;******************************************************************************
;                                                                             *
;    Files required:         P18F4550.INC                                     *
;			     dwengo.LKR               			  						  *
;									     									  *
;                                                                             *
;                                                                             *
;******************************************************************************

	LIST P=18F4550, F=INHX32	;directive to define processor
	#include <P18F4550.INC>	;processor specific variable definitions



; definitie variabelen
		UDATA 0x300

WREG_TEMP	RES	1	;variable in RAM for context saving 
STATUS_TEMP	RES	1	;variable in RAM for context saving
BSR_TEMP	RES	1	;variable in RAM for context saving

DVAR1		RES 1
DVAR2		RES 1
DVAR3		RES 1

honderdtal	RES 1
tiental		RES 1
eenheid		RES 1
deeltal		RES 1
quotient	RES 1

voorbeeld 	RES 1	;op deze manier maak je een geheugenplaats van 1 byte die
; je kan gebruiken via de naam "voorbeeld"

;hier eventueel extra variabelen toevoegen
teller		RES 1
; Access Bank

		UDATA_ACS

EXAMPLE		RES	1	; example of a variable in access RAM



;******************************************************************************
;EEPROM data
; Data to be programmed into the Data EEPROM is defined here
;******************************************************************************


DATA_EEPROM	CODE	0xf00000

	;	DE	"Test Data",0,1,2,3,4,5

;******************************************************************************
;Reset vector
; This code will start executing when a reset occurs.
;******************************************************************************
	org 0x0
	goto 0x2000

	org 0x08
	goto 0x2008

	org 0x18
	goto 0x2018


RESET_VECTOR	CODE	0x2000
		movlb  0x03
		goto	Main		;go to start of main code

HI_INT_VECTOR	CODE	0x2008

		goto	HighInt		;go to high priority interrupt routine

LOW_INT_VECTOR	CODE	0x2018

		goto	LowInt		;go to low priority interrupt routine

;******************************************************************************
;High priority interrupt routine
; The high priority interrupt code is placed here to avoid conflicting with
; the low priority interrupt vector.
;******************************************************************************
		CODE

HighInt:
	btfsc INTCON,RBIF
	bra check
	bra HighIntEinde
	
check:
	btfss PORTB,5
	bra HighIntEinde
	btfss PORTB,4
	bra KnopN
	bra HighIntEinde
	
KnopN:
	btfss PORTB,4
	bra KnopS

KnopS:
	btfss PORTB,5
	btg LATD,0
	bra check
	
HighIntEinde:
	bcf INTCON,RBIF
	bcf INTCON,INT0IF
	bcf INTCON3,INT1IF
	call Delay
	Retfie FAST			; terugkeren

;******************************************************************************
;Low priority interrupt routine
; The low priority interrupt code is placed here.
; This code can be removed if low priority interrupts are not used.
;******************************************************************************
LowInt:
		movff	STATUS,STATUS_TEMP	;save STATUS register
		movff	WREG,WREG_TEMP		;save working register
		movff	BSR,BSR_TEMP		;save BSR register

;	*** low priority interrupt code goes here ***


		movff	BSR_TEMP,BSR		;restore BSR register
		movff	WREG_TEMP,WREG		;restore working register
		movff	STATUS_TEMP,STATUS	;restore STATUS register
		retfie

;******************************************************************************
; Hoofdprogramma
; Schrijf al je code onder het label main
; subroutines voeg je onderaan toe
; macro's bovenaan
;******************************************************************************

Main:


; ===========
; MACRO's
; ===========

#include "macro.asm"


; ===============
; HOOFDPROGRAMMA
; ===============

	setf TRISB			; port N als ingang
	clrf TRISD			; port D als uitgang
	bcf RCON,IPEN		; prioriteiten uit
	bsf INTCON,GIE		; glob.int. aan
	bsf INTCON,RBIE		; int portb aan
	bsf INTCON,INT0IE	; int 0 aan
	bsf INTCON3,INT1IE	; int 1 aan
lus:
	sleep
	bra lus

; ============
; SUBROUTINES
; ============

#include "subroutine.asm"

;******************************************************************************
;Einde programma
;******************************************************************************
	
	END
