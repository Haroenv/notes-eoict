# Overzicht commando's

Door: Hanne Goossens

```sql
select table (...) engine=''; #tabel aanmaken
drop table ...;	#tabel verwijderen
unsigned; #enkel positieve getallen
zerofill; #voorloopnullen toevoegen
float;	#reeële getallen waarvoor grote precisie niet nodig is
double(m,d); #m: aantal digits; d: aantal na de komma
decimal(m,d); #idem, gebruik voor geld
```

#Examenantwoorden

#2013-2014

Door: Robin Maenhout

```sql
SELECT brandstof, COUNT(*) FROM autos INNER JOIN autoinfo ON autos.autoinfo_id=autoinfo.id GROUP BY brandstof ORDER BY Count(*) DESC LIMIT 1;
SELECT COUNT(DISTINCT(autoinfo.bouwjaar)) AS aantal, verkopers.naam FROM verkopers INNER JOIN autos ON verkopers.id=autos.verkopers_id INNER JOIN autoinfo ON autoinfo.id=autos.autoinfo_id WHERE verkopers.naam='Katja';
SELECT autos.chassisNR, autoinfo.basisprijs+SUM(opties.prijs) AS verkoopprijs FROM opties INNER JOIN autos_has_opties ON autos_has_opties.opties_id=opties.id INNER JOIN autos ON autos.chassisNR=autos_has_opties.autos_chassisNR INNER JOIN autoinfo ON autoinfo.id=autos.autoinfo_id GROUP BY autos.chassisNR;
```
