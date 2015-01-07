#Labo 1: Virtuele machines

##Aanmaak virtuele schijf

Nieuwe vdi gemaakt voor windows 7. Deze staat opgeslagen in  C:\Virtual	Machines\Virtuele Machines Studenten\1ICT\Haroen Viaene\7\.

Er werd voor een disk van 25 GB gekozen. Er komen een hoop bestanden in die map, vooral partities van de schijf (13 partities), een .vmdk-bestand die de schijf significeert, een .vmx.lck-bestand, een configuratie- en een team-bestand.

Het .vmdk-bestand is slechts 2 KB omdat de feitenlijke schijf opgedeeld is in 13 partities van 320 KB.

// Werd opnieuw geplaatst zonder de partities hierna. Hierdoor zijn die 13 partities verwijderd en is het .vmdk-bestand nu 3264 KB.

##Windows 7

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

##Windows Server

Windows Server werd analoog geïnstalleerd. Er werd echter gestopt voor de effectieve installatie ervan. Nu heb ik echter gekozen om bij de setup al te kiezen voor de iso van Windows Server 2012 op te starten bij installatie. Hierdoor start de computer direct op in de installatie.

Door "boot into BIOS" te kiezen kan je de opstartvolgorde wijzigen in de tab "boot" en dan met de plus-en min-knoppen verplaats je de volgorde.

##Netwerkinstellingen

Je kan kiezen tussen Bridged, NAT, Host-Only en Custom. Als je Bridged kiest, is er een speciale netwerkkaart enkel voor de VM, bij Bridged neem je het IP-adres en netwerk van de Host over (standaard). Als je voor Host-Only kiest, krijg je een netwerk met enkel de Host.

##Schone lei

Hierna zijn alle bestanden van VMWare verwijderd die deze les gemaakt zijn, behalve de .vmdk die gekopieerd was naar C:\Virtual	Machines\Virtuele Machines Studenten\1ICT\Haroen Viaene\

In de volgende les wordt die vmdk geopend.