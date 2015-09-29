; ============
; SUBROUTINES
; ============


; Versturen puls naar enable - LCD op Dwengo bord
; ===============================================
Epuls
	call 	DelayLCD	; wachten
	bsf		LATE,2		; E hoog maken
	call 	DelayLCD	; wachten
	bcf		LATE,2		; E laag maken
	return

	
; Delay routine - LCD op Dwengo bord
; ==================================
DelayLCD				; moet minimaal 160µs zijn (48MHz)
   	movlw 	0x0F
   	movwf 	DVAR1
Delay1
	movlw 	0xFF
	movwf 	DVAR2
Delay2
	decfsz 	DVAR2
	goto 	Delay2
   	decfsz 	DVAR1
   	goto 	Delay1
   	return

; Delay routine - algemeen
; ========================

Delay
	movlw 	0x10 			;stel hier duur delay in
	movwf 	DVAR3
DelayExtra
	movlw 	0xFF
	movwf 	DVAR2 		
DelayOuter
	movlw 	0xFF
	movwf 	DVAR1 		
DelayInner
	decfsz 	DVAR1
	goto 	DelayInner
	decfsz 	DVAR2
	goto 	DelayOuter
	decfsz 	DVAR3
	goto 	DelayExtra
	return

; Decimaal getal splitsen in cijfers (max. 255)
; =============================================

omzettingDecimaal
       clrf    eenheid
       clrf    tiental
       clrf    honderdtal
deling1
       clrf    quotient
lusdeling1
       incf    quotient                        ;quotient verhogen
       movlw   D'10'
       subwf   deeltal                       ;tien aftrekken
       bc      lusdeling1                      ;zolang resultaat groter dan nul was blijven uitvoeren
       addwf   deeltal                         ;1 keer te veel afgetrokken, weer bijtellen
       movff   deeltal,eenheid
       decf    quotient                        ;quotient een keer te veel verhoogd, weer verminderen

       ;quotiënt eerste deling bestaat nog uit twee decimale cijfers
       ;opnieuw "delen", rest is cijfer voor tientallen, quotient is cijfer voor honderdtallen
       movff   quotient,deeltal
deling2
       clrf    quotient
lusdeling2
       incf    quotient
       movlw   D'10'
       subwf   deeltal
       bc      lusdeling2
       addwf   deeltal
       movff   deeltal,tiental
       decf    quotient
	   movff   quotient,honderdtal
       return	