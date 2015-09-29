; ===========
; MACRO's
; ===========


; INITIALISATIE LCD op Dwengo bord
; ================================
LCD_Init Macro
; poorten instellen LCD (Dwengo)
	movlw 	0Ah 
	movwf 	ADCON1 		; RBE als digitale poorten

	clrf	TRISD		; poort D = data LCD
	bcf		TRISC,0  	; LED verlichting LCD

	bcf		TRISE,0	    ; RS
;	bcf		TRISE,1		; RW (aan GND bij enkel schrijven)
	bcf		TRISE,2		; E	
	
; achtergrondverlichting aan
	bsf		LATC,0

; wachten op stabilisatie LCD bij aanleggen voedingsspanning
	movlw 	0xFF
	movwf 	DVAR3
DelayLang:
	call 	DelayLCD		
   	decfsz 	DVAR3
   	goto 	DelayLang

; LCD initialiseren
	bcf		LATE,0  	; RS laag
	bcf		LATE,2		; E laag
	
	movlw	B'00000001'	; clear display
	movwf	LATD
	call	Epuls

	movlw	B'00111000'	; interface length: byte, 2 lijnen, 5x7 dots
	movwf	LATD
	call	Epuls

	movlw	B'00001100'	; display aan, geen cursor, geen blinking
	movwf	LATD
	call	Epuls

	movlw	B'00000110'	; richting cursorpositie
	movwf	LATD
	call	Epuls

	movlw	B'00000001'	; clear display
	movwf	LATD
	call	Epuls
	
	EndM

; Adres op eerste lijn - LCD op Dwengo bord
; =========================================
LCD_Lijn1 Macro
	bcf		LATE,0    	; RS laag
	bcf		LATE,2		; E laag
	movlw	B'10000000'	; move cursor to display (adres 0 = 1e lijn)
	movwf	LATD
	call	Epuls
	bsf		LATE,0  	; RS hoog
	bcf		LATE,2		; E laag
	
	EndM
	
; Adres op tweede lijn - LCD op Dwengo bord
; =========================================
LCD_Lijn2 Macro
	bcf		LATE,0    	; RS laag
	bcf		LATE,2		; E laag
	movlw	B'10101000'	; move cursor to display (adres 0x28 = 2e lijn)
	movwf	LATD
	call	Epuls
	bsf		LATE,0    	; RS hoog
	bcf		LATE,2		; E laag
	
	EndM

; Schrijven karakter naar huidige positie - LCD op Dwengo bord
; ============================================================
LCD_Char MACRO karakter
	movlw  	karakter
	movwf	LATD
	call	Epuls
	
	EndM


; Schrijven decimaal getal naar huidige positie - LCD (max. 255)
; ==============================================================

LCD_Getal Macro getal  
	movlw	getal
	movwf	deeltal
	call 	omzettingDecimaal

	movff 	honderdtal,WREG
	addlw 	'0'
	movwf 	LATD
	call 	Epuls

	movff 	tiental,WREG
	addlw 	'0'
	movwf 	LATD
	call 	Epuls

	movff 	eenheid,WREG
	addlw 	'0'
	movwf 	LATD
	call 	Epuls

	EndM