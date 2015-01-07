##Hoofdstuk 7: NTFS-rechten
###7.1 Rechten op mappen en bestanden
4. SYSTEM, student en Administrators (Administrator)
5. cd Documents, dan icacls Labo7
6. lezen en uitvoeren, mapinhoud weergeven, lezen. (OI), (CI) en (RX)
7. takeown /F C:\Users\student\Documents\Labo7
    "Fout: De huidig aangemelde gebruiker heeft geen eigenaarsmachtigingen
    voor het bestand (of de map) C:\Users\student\Documents\Labo7."
8. Je moet bij het tabblad beveiliging op geavanceerd klikken, dan op eigenaar, dan op bewerken (hiervoor moet je administrator zijn)
9. Op dezelfde manier

###7.2 Doorgeven van rechten

2. account heeft nu enkel (OI) en (CI) (lezen en uitvoeren en lezen), dit is omdat dit een tekstbestand is en geen map.
3. bij eigenschappen van Labo7 pas je beveiliging > geavanceerd > machtigingen wijzigen > account > bewerken > enkel voor deze map
4. nee, dit is nog zoals het was voordien
5. eerst: 'icacls .\Labo7 /remove:g account /T', dan 'icacls .\Labo7\\* /reset'

###7.3 Speciale rechten

1. beveiliging > wijzigen > weigeren bij schrijven (voor student)
3. Bestanden maken/gegevens schrijven, Mappen maken/gegevens toevoegen, Kenmerken schrijven, Uitgebreide kenmerken schrijven, Machtigingen lezen
4. Hij kan geen submappen meer maken
5. icacls /remove
6. read and execute, write

###7.4 Kopiëren en verplaatsen van bestanden

1. Beheerder kan enkel lezen
2. Standaard
