##Labo 9: Beveiliging en Schijfbeheer

###9.1 Windows Firewall
1. services > Windows firewall > handmatig. Windows firewall >  regels voor binnenkomende verbindingen > nieuwe regel > poort > 80 TCP > iedereen.
2. netsh
3. /
4. netstat -a

###9.2 Logboeken
1. Computerbeheer > logboeken
2. 
  Windows-logboeken > systeem: dingen die belangrijk zijn voor het hele systeem
  Windows-logboeken > beveiliging: Microsoft security auditing
  Windows-logboeken > Toepassing: alle dingen die met (third-party)programma's te maken hebben
3. niveaus: fout, waarschuwing en informatie
4. alle gebeurtenissen opslaan (kan je terug openen). Logboek wissen. 
5. filteren: niveau = fout
6. rechtermuisknop, eigenschappen Max logboekgrootte 2048 kB
7. vinkjes op geslaagde en mislukte pogingen. Toont het in logboek

### 9.3 Schijfbeheer
1. Nieuwe harde schijf (SCSI), optie uit
2. opgestart
3. Nieuw eenvoudig volume wizard > initialiseren
4. 500 MB / NTFS / N: / V1
5. 500 MB (kleiner dan 32 GB) / FAT32 / O: / V2
6. rechtermuisknop: stationsletter wijzigen > P:
7. Dit gaat niet op FAT32
8. convert P: /fs:NTFS
9. nu kunnen er uiteraard wel NTFS-rechten toegekend worden.

###9.4 Quotumbeheer
1. aangemaakt
2. eigenschappen > quotum > inschakelen > 5 MB. 
3. waarschuwing 4,5 MB
4. vinkje gebeurtenis registreren
5. Limiet geldt ook voor administrator
6. bij een harde limiet kan er helemaal niet over de limiet gegaan worden, bij een zachte wel.

###9.5 Dynamische schijven
1. toegevoegd
2. computerbeheer
3. 