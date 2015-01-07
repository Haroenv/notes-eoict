#Labo Windows

Haroen Viaene

2014-2015

1eo-ict 10

##Labo 1: Virtuele machines

###Aanmaak virtuele schijf

Nieuwe vdi gemaakt voor windows 7. Deze staat opgeslagen in  C:\Virtual	Machines\Virtuele Machines Studenten\1ICT\Haroen Viaene\7\.

Er werd voor een disk van 25 GB gekozen. Er komen een hoop bestanden in die map, vooral partities van de schijf (13 partities), een .vmdk-bestand die de schijf significeert, een .vmx.lck-bestand, een configuratie- en een team-bestand.

Het .vmdk-bestand is slechts 2 KB omdat de feitenlijke schijf opgedeeld is in 13 partities van 320 KB.

// Werd opnieuw geplaatst zonder de partities hierna. Hierdoor zijn die 13 partities verwijderd en is het .vmdk-bestand nu 3264 KB.

###Windows 7

Hierna wordt het OS geïnstalleerd vanuit een ISO-bestand dat in \ISO\ stond. Dit is een Windows 7 64-bit versie. Die iso werd in de settings verwezen als een nieuwe CD-drive

Terwijl Windows aan het installeren is antwoord ik op de vragen die gesteld worden.

A) Het verschil tussen Belgisch (punt) en Belgisch (komma) is dat Belgisch (komma) de versie van het AZERTY-toetsenbord is die in Frankrijk gebruikt wordt is. Een paar kleine verschillen in de weinig-gebruikte toetsen aan de rechterkant

//source: http://help.keyman.com/keyboard/belgian_comma/1.0/belgian_comma.php

B) Systeemvereisten Windows 7: http://windows.microsoft.com/nl-nl/windows7/products/system-requirements

// een paar keuzes uit die lijst: 1GB RAM, 1GHz processor, 16 GB schijfruimte, DirectX 9

C) De Unity-modus in VMWare is een modus waarin je enkel de relevante schermen ziet van je VM. Hierdoor krijg je een "naadloze" omgeving.

D) Toen ik HCL zag dacht ik aan zoutzuur, maar ik veronderstel dat dit niet de vraag was. Daarom zocht ik op Google en vond ik dat het een  IT & software development-bedrijf is die ook een kantoor in België (Brussel) heeft.

// source: https://www.google.be/url?sa=t&rct=j&q=&esrc=s&source=web&cd=3&cad=rja&uact=8&ved=0CDIQFjAC&url=http%3A%2F%2Fwww.hcltech.com%2Fgeo-presence%2Fbelgium&ei=CoIiVMfSFqbP7gbdu4DYCg&usg=AFQjCNFVNk_Hkfh5btY5yZvD3Ed3NNQfWw&bvm=bv.75775273,d.ZGU

//noot: HCL staat blijkbaar voor hardware compatibility list, een lijst van hardwares die compatibel zijn met een bepaalde OS.

// Ondertussen vroeg de installatie van Windows 7 nog voor een paar dingen zoals de activatie-code en de tijdszone en zo, die werden gewoon snel ingevuld. Snel hierna kwam ik ook op de desktop uit (10:38)

E) FAT32 kan o.a. grotere bestandsformaten aan. Werd geïntroduceerd samen met Windows XP.

// source: http://technet.microsoft.com/en-us/library/cc940351.aspx

F) NTFS staat voor New Technology File System (wikipedia)

G) NTFS vs FAT32 in getallen: http://www.ntfs.com/ntfs_vs_fat.htm

Noot: Ik ben gemist bij de installatie en heb voor JOHN-PC en gebruiker John gekozen. Ik heb ook gekozen voor publiek netwerk.

Het verschil tussen home, work en public is dat je bij public geen andere computers kan zien en dat jij "onzichtbaar" bent voor anderen. Bij Work kan je network discovery wel gebruiken, maar je kan geen nieuwe homegroup verbinden of aanmaaken. Dit is wel mogelijk bij een Home-netwerk. Ik had voor public gekozen omdat ik momenteel geen nood zag aan netwerken.

//source: http://windows.microsoft.com/en-us/windows/choosing-network-location#1TC=windows-7

###Windows Server

Windows Server werd analoog geïnstalleerd. Er werd echter gestopt voor de effectieve installatie ervan. Nu heb ik echter gekozen om bij de setup al te kiezen voor de iso van Windows Server 2012 op te starten bij installatie. Hierdoor start de computer direct op in de installatie.

Door "boot into BIOS" te kiezen kan je de opstartvolgorde wijzigen in de tab "boot" en dan met de plus-en min-knoppen verplaats je de volgorde.

###Netwerkinstellingen

Je kan kiezen tussen Bridged, NAT, Host-Only en Custom. Als je Bridged kiest, is er een speciale netwerkkaart enkel voor de VM, bij Bridged neem je het IP-adres en netwerk van de Host over (standaard). Als je voor Host-Only kiest, krijg je een netwerk met enkel de Host.

###Schone lei

Hierna zijn alle bestanden van VMWare verwijderd die deze les gemaakt zijn, behalve de .vmdk die gekopieerd was naar C:\Virtual	Machines\Virtuele Machines Studenten\1ICT\Haroen Viaene\

In de volgende les wordt die vmdk geopend.

##Labo 2

Blijkbaar was het niet nodig om alle bestanden van de vorige les te verwijderen. Gelukkig kon deze info nog terug zonder problemen uit de prullenmand gehaald worden.

Nu de computer juist opgestart is, wordt er aan de opdracht van les 2 begonnen. Om aan deze opdracht te beginnen wordt cmd.exe opgestart door windows-r cmd.exe te gebruiken binnen de virtuele machine.

###1.Basiscommando's

1. De virtuele machine wordt opgestart.
2. dankzij het commando "cd c:\" raak je in de c-schijf
3. als nu "dir /AH" gebruikt wordt zijn onzichtbare bestanden zichtbaar gemaakt.
4. dankzij "cd U"tab raak ik in de map Users, dan idem naar student en uiteindelijk in de map "c:\users\student\documents".
5. Eens in die map genavigeerd maakt het commando "mkdir test" een submap test in c:\users\student\documents\. Dit werd gecontroleerd door het commando "tree" (of kon ook door "dir")
6. Dankzij "cd test" en "echo test > test.txt", wordt een nieuw tekstdocumentje met de inhoud test gemaakt. Idem wordt een documentje test2 met inhoud 2 en test3 met inhoud "Hello World!" gemaakt.
7. dankzij "copy *.txt testcomb.txt" worden die drie zinnetjes elk op een eigen regel in testcomb.txt gezet.
8. het gecombineerde bestand wordt weer geopend door het commando "type testcomb.txt". Hierin wordt er bevestigd wat er in het bestand zit.
9. dankzij "cd .."en "xcopy test backup" wordt een backupmap gemaakt. Er werd gevraagd of "backup" een map of bestand was. "D" invoeren duidde aan dat backup wel degelijk een map is.
10. Met notepad werd in /test het bestand test2 aangepast zodat er twee lijnen lager "TEST" staat, en idem voor test3 in de map /backup.

##Labo 3: Powershell

### Basisopdrachten

1. Get-ChildItem -File | sort length -Descending
2. Get-ChildItem | ForEach-Object{Write-Host $_.mode}
3. Get-Command Set-* | Write-Host
4. Get-Command Set-* | ForEach{ if( $_.CommandType -eq "Cmdlet") {Write-Host $_.name} }

### Korte scripts

1.
````powershell
Clear-Host
Get-Process | Select-Object Company | Group-Object Company | Sort-Object Count
````

2.
````powershell
Param([string] $bron $doel)
robocopy  $bron $doel /B
dir $doel
````

##Labo 4: Opstarten

###0 voorbereiding

Er werd een snapshot met de naam "Windows 7 opgestart" gemaakt.

###1 BIOS vs uEFI

Waarom is UEFI beter dan BIOS:
	sneller (meestal)
	veiliger
	werkt op meer dan x86
	geen MBR (master boot record) meer nodig
	grotere disks (>2TB met GUID partitioning table)
	drivers en architecture maken niet uit
	je hebt al netwerkverbinding etc. voor opstart OS
	modulair

###2 Windows Dual boot

"Windows 98.vmdk" werd gekopiëerd naar de map C:\"Virtual Machines"\"Virtuele Machines Studenten"\1ICT\"Haroen Viaene 2".

In de instellingen van Windows 7.vmx werd de harde schijf van 98 toegevoegd.

Hij start op in Windows 98 omdat die eerder stond in de boot record. Nadat dit veranderd is, staat Windows 7 wel degelijk eerste in de lijst.

###3 bcdedit

bcdedit geeft een aantal gegevens weer over de opstartprocedure in Windows. Dit zijn dingen zoals id, device, locale, timeout etc.

bcdedit /create /d 'Linux' /application osloader
bcdedit /set {5cc63c74-e82e-11e0-b09e-eaab89ebc234}  device partition=C:
bcdedit /displayorder {5cc63c74-e82e-11e0-b09e-eaab89ebc234} /addlast
bcdedit /timeout 32
EasyBCD > add new entry > windows 98
Windows 98 is er bijgekomen
In de C-schijf is er een nieuw mbr-bestandje in /NST gekomen.
bcdedit

###4 Recovery Console

64 bit

De ISO werd in de BIOS eerst geplaatst.

Er wordt op "repair your computer geklikt"

Daarna op opdrachtprompt

`bootrec /rebuildbcd`

	* mogelijkheden: /rebuildbcd (herstelt de bcd), /fixmbr (repareer master boot record, zonder te overschrijven), /fixboot (nieuwe bootsector), /scanOS (scant voor compatible os's), bcdedit /delete {5cc63c74-e82e-11e0-b09e-eaab89ebc234} 

###5 Instellingen

Configuratiescherm > Systeem > Geavanceerde systeeminstellingen > Geavanceerd > Opstart- en herstelinstellingen > Lijst met besturingssystemen 15 seconden weergeven

%SystemRoot%\MEMORY.DMP (C:\Windows\MEMORY.DMP)

##Labo 5: Processen 

###1 Taakbeheer
1. ctrl shift esc, tab details, rechtermuisknop op de titeltjes, select colums, klik PID en CPU Time
2. Start SuperPi, SuperPi gebruikt maar 1 core, dus 25%. Toast ook 25% omdat het 1 core gebruikt (opvallend is dat het niet zichtbaar is). Deze programma's belasten 1 core volledig, dus zijn relatief belastedn. SuperPi berekent de decimalen van pi en Toast doet een CPU-benchmark.
3. Bij het opstarten tot 10% cpu, maar dit wordt snel lager. Dit is verspreid onder verschillende processen zoals VMware Workstation VMX, VMware.vmx...
4. Er wordt niet direct een verschil gemerkt omdat er niet veel power-hungry processen bezig zijn op het moment. Als gewone gebruiker mag je enkel in "High" zetten. 
5. Nu wordt het proces dat in "low" stond verlaagt in prioriteit, en zal trager werken. Het is echter niet zo merkbaar

###2 Systeem Monitor

1. gestart
2. rood

##Labo6 (Bram Van den Bulcke)

###6.1 OPBOUW REGISTER

1. Maak screensaver
2. HKEYCURRENTUSER\Software\Microsoft\Windows\CurrentVersion\Screensavers\ssText3d\screen1
3. Bij HKEYUSERS\...
4. Ik doe ICT
5. Het is veranderd naar mijn naam.
6. HKEY_LOCAL_MACHINE\SYSTEM\Select

###6.2 INSTELLINGEN VERANDEREN

1. HKEYCURRENTUSER\Software\Internet Explorer\TypedURL
2. Is aangepast
3. HKEYCURRENTUSER\Software\Microsoft\Windows\CurrentVersion\Run => Leeg bij VM / Bij vaste pc "Papercut"

###6.3 IMPORTEREN/EXPORTEREN

1. 1.617Kb
2. De screensaver is veranderd naar die van de gebuur.

###6.4 PROCESS MONITOR

1. add filter; Path contains ssText3d includes
2. RegSetValue, HKCU\Software\Microsoft\Windows\Current Version\Screensavers\ssText3d\Displaystring
3. Show file system activity, filteren op wordpad.exe. / recent => HKCU\Software\Microsoft\Windows\Current Version\Applets\Wordpad\ Recent File List

###6.5 OPBOUW

1.
````
%SystemDrive%\boot
%SystemRoot%\System32\Config\Sam
%SystemRoot%\System32\Config\Security
%SystemRoot%\System32\Config\Software
%SystemRoot%\System32\Config\System
%SystemRoot%\System32\Config\System
````


###2. k ntuser.dat / ntuser.dat.log (data & log bestand).

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

##Labo 8: Gebruikersaccounts
###8.1 Nieuwe gebruikers aanmaken
1. Configuratiescherm > gebruikers en accounts > Gebruikersaccounts
2. Ja, als beheerder kan je kiezen tussen Standaardgebruiker en Administrator (Admin heeft meer toestemmingen)
3. slider op onderste stand
4. Configuratiescherm > gebruikers en accounts > Accounts beheren > nieuw maken > standaard
5. Ja
6. gebruik makend van het administrator-wachtwoord
7. Hier moet je admin voor zijn
8. Accounts deze en vorige les gemaakt hebben geen paswoord. (Windows raadt aan je wachtwoord acht tekens lang te maken, niet je echte naam of bedrijfsnaam, geen volledig woord, wijkt duidelijk af van eerdere wachtwoorden (dit is volgens controlepaneel)) secpol.msc > Accountbeleid > wachtwoordbeleid > complexiteit: 6 tekens lang, moet 3/4 van elk bevatten: a-z, A-Z, 0-9, !$#%.
9. C:\Users\gebruiker

###8.2 Computerbeheer
1. mmc.exe > <kbd>ctrl</kbd>+<kbd>M</kbd> > Computerbeheer
2. Computerbeheer > Systeemwerkset > Lokale gebruikers en groepen > Gebruikers > <kbd>rechtermuisknop</kbd> > voeg gebruiker toe
3. Gewone gebruiker
4. lid van > toevoegen > gasten
5. Hoofdgebruiker kan alles wat Administrator kan, maar enkel voor zijn eigen account //fout

###8.3 Groepen
1. ook in mmc > ... > groepen > rechtermuisknop
2. bij het instellen wordt dit gekozen met toevoegen ...
3. secpol.msc > lokaal beleid > Systeem afsluiten >  verwijderen > ok
4. secpol.msc > accountbeleid > accountvergendelingsbeleid > account vergrendelen durende 5 min, drempel 2

###8.4 Authenticatie van services
1. Staat op 10.129.18.13/labo/windows
2. Alles Werkt! De Apache Web Server is geinstalleerd op deze Web Site
3. 
  * mmc.exe > gebruikers > nieuw > Apacheuser/Test
  * htdocs schrijfrechten geven
  * logs lees- en schrijfrechten geven
  * services > Apache2 > Aanmelden
  * Opnieuw opstarten

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