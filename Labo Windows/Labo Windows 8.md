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