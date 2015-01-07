#Labo6

##6.1 OPBOUW REGISTER

1. Maak screensaver
2. HKEYCURRENTUSER\Software\Microsoft\Windows\CurrentVersion\Screensavers\ssText3d\screen1
3. Bij HKEYUSERS\...
4. Ik doe ICT
5. Het is veranderd naar mijn naam.
6. HKEY_LOCAL_MACHINE\SYSTEM\Select

##6.2 INSTELLINGEN VERANDEREN

1. HKEYCURRENTUSER\Software\Internet Explorer\TypedURL
2. Is aangepast
3. HKEYCURRENTUSER\Software\Microsoft\Windows\CurrentVersion\Run => Leeg bij VM / Bij vaste pc "Papercut"

##6.3 IMPORTEREN/EXPORTEREN

1. 1.617Kb
2. De screensaver is veranderd naar die van de gebuur.

##6.4 PROCESS MONITOR

1. add filter; Path contains ssText3d includes
2. RegSetValue, HKCU\Software\Microsoft\Windows\Current Version\Screensavers\ssText3d\Displaystring
3. Show file system activity, filteren op wordpad.exe. / recent => HKCU\Software\Microsoft\Windows\Current Version\Applets\Wordpad\ Recent File List

##6.5 OPBOUW

1.    %SystemDrive%\boot
	%SystemRoot%\System32\Config\Sam
	%SystemRoot%\System32\Config\Security
	%SystemRoot%\System32\Config\Software
	%SystemRoot%\System32\Config\System
	%SystemRoot%\System32\Config\System



##2. k ntuser.dat / ntuser.dat.log (data & log bestand).
