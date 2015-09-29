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

voorbeeld 	RES 1	;op deze manier maak je een geheugenplaats van 1 byte die je kan gebruiken via de naam "voorbeeld"

;hier eventueel extra variabelen toevoegen
teller	    RES 1

; Access Bank

		UDATA_ACS

EXAMPLE		RES	1	; example of a variable in access RAM



;******************************************************************************
;EEPROM data
; Data to be programmed into the Data EEPROM is defined here


DATA_EEPROM	CODE	0xf00000

	;	DE	"Test Data",0,1,2,3,4,5

;******************************************************************************
;Reset vector
; This code will start executing when a reset occurs.
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
		CODE

HighInt:

	Retfie FAST


;******************************************************************************
;Low priority interrupt routine
; The low priority interrupt code is placed here.
; This code can be removed if low priority interrupts are not used.
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

Main:


; ===========
; MACRO's
; ===========

#include "macro.asm"

; ===============
; HOOFDPROGRAMMA
; ===============
	LCD_Init
	;bra opgave1
	;bra opgave2
	bra opgave3

opgave1:
	bsf TRISB,1 ; knop W als ingang
	bsf TRISB,0 ; know E als ingang
	clrf TRISD
	clrf LATD
	bsf LATD,0

lus:
	btfss PORTB,1 ; W inlezen
	rrncf LATD,1,0
	btfss PORTB,0 ; E inlezen
	rlncf LATD,1,0
	call Delay
	bra lus
	
opgave2:
	bsf TRISB,4 ; knop N als ingang
	bsf TRISB,5 ; knop S als ingang
	clrf LATD

loop:
	LCD_Lijn1
	btfss PORTB,4 ; N inlezen
	bra noord
	btfss PORTB,5 ; S inlezen
	bra zuid
	bra loop

noord:
	movlw 'N'
	movwf LATD
	call Epuls
	bra loop

zuid:
	movlw 'S'
	movwf LATD
	call Epuls
	bra loop

opgave3:
	bsf TRISB,4 ; knop N als ingang
	bsf TRISB,5 ; knop S als ingang
	bsf TRISB,2 ; knop C als ingang
	movlw 0x00
	addlw 0x30
	movwf teller
	clrf LATD

lusje:
	LCD_Lijn1
	movlw 0x01
	btfss PORTB,4 ; N inlezen
	bra north

	btfss PORTB,5 ; S inlezen
	bra south

	btfss PORTB,2 ; C inlezen
	bra center

	movwf teller
	movff teller,LATD
	call Epuls
	bra lusje

center:
	btfsc PORTB,2
	call Delay
	movlw 0x00
	movf teller,W
	bra lusje

south:
	btfsc PORTB,5
	call Delay
	subwf teller
	
north:
	btfsc PORTB,4
	call Delay
	addwf teller
; ============
; SUBROUTINES
; ============

#include "subroutine.asm"

;******************************************************************************
;Einde programma
	
	END
