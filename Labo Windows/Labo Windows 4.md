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

bootrec /rebuildbcd
	mogelijkheden: /rebuildbcd (herstelt de bcd), /fixmbr (repareer master boot record, zonder te overschrijven), /fixboot (nieuwe bootsector), /scanOS (scant voor compatible os's),
bcdedit /delete {5cc63c74-e82e-11e0-b09e-eaab89ebc234} 

###5 Instellingen

Configuratiescherm > Systeem > Geavanceerde systeeminstellingen > Geavanceerd > Opstart- en herstelinstellingen > Lijst met besturingssystemen 15 seconden weergeven

%SystemRoot%\MEMORY.DMP (C:\Windows\MEMORY.DMP)