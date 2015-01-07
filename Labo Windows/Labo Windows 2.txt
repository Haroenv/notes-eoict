#Labo 2

Blijkbaar was het niet nodig om alle bestanden van de vorige les te verwijderen. Gelukkig kon deze info nog terug zonder problemen uit de prullenmand gehaald worden.

Nu de computer juist opgestart is, wordt er aan de opdracht van les 2 begonnen. Om aan deze opdracht te beginnen wordt cmd.exe opgestart door windows-r cmd.exe te gebruiken binnen de virtuele machine.

##1.Basiscommando's

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