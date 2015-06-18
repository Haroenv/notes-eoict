#  Overzicht commando's

Door: Hanne Goossens

```sql
create table (...) engine='';	# tabel aanmaken
drop table ...;		# tabel verwijderen
unsigned;			# enkel positieve getallen
zerofill;			# voorloopnullen toevoegen
float;				# reeële getallen waarvoor grote precisie niet nodig is
double(m,d);		# m: aantal digits; d: aantal na de komma
decimal(m,d);		# idem, gebruik voor geld
char(n);			# korte string met lengte n
varchar(n);			# idem, max 255 chars
text/blob;			# langere string, text is niet hoofdlettergevoelig
date,time,datetime;	# YY-MM-DD; HH:MM:SS; YYYY-MM-DD; HH:MM:SS
# zet tussen aanhalingstekens
year;				# YYYY
now();				# nu
timestamp;			# wordt automatisch aangepast aan huidige tijd, YYYYMMDDHHMMSS
unix-timestamp;		# epochtijd in s
enum('bla','bla');	# verzameling van strings in hoofdletters
is null/ is not null;	# niet '=' of 'like' gebruiken voor null
auto_increment;		# automatisch +1 in combinatie met not null, pk, unique
alter tabelnaam add kolomnaam;	# kolom toevoegen
alter tabelnaam change kolomnaam;	# verander kolomdefinitie
alter tabelnaam rename to nieuweTabelnaam;	# verander tabelnaam
alter tabelnaam drop kolomnaam;	# drop een bepaalde kolom
insert into tabelnaam values(...);	#nieuwe records toevoegen aan een tabel (in volgorde van de kolommen)
update tabelnaam set ... = ...;		# verander een bepaalde waarde
delete from tabelnaam where ...;	# verwijder bepaalde records
# tip: test deze eerst met select
select kolomnaam from tabelnaam		# data opvragen
	where ... = ...
	where ... > ...
	where ... < ...
	where ... like '...%'
	where ... between ... and ...
	where ... in (...,...,...)
	order by kolomnaan
	desc
	limit a b; 			# a is de limit; b de offset
select distinct kolomnaam from tabelnaam;	# dubbels filteren
select max(kolomnaam) from tabelnaam;		# maximum
select count(waarde) from tabelnaam;		# tel het aantal
select sum(waarde) from tabelnaam;			# de som (van numerieke waarden)
select ... as iets from tabelnaam;			# verander de naam waarop het weergegeven wordt
year(datum), dayofmonth(datum);				# dag vd maand/jaar ve datum
to_days(curdate()), to_days(datum);			# dagen verschil
adddate(now(), interval 1 day);				# voeg een datum toe
subdate(not(), interval 1 day);				# trek een datum afs
select ...  from ... inner join ... on ... = ...; #*
select ...  from ... left join ... on ... = ...;
group by;	# groepeer (gebruik bij aggregatiefunctie*)
having; 	# voorwaarde bij group by
index (kolomnaam(n));	# index van een kolom aanmaken*
alter tabelnaam add index(kolomnaam(n));
create index ... on ... (kolomnaam(n));
create index ... on ... (kolomnaam(n);anderenaam(m));
drop index;	# verwijder index
alter tabelnaam add unique(kolomnaam(n));
create unique index ... on tabelnaam(kolomnaam(n)); # constraint voor index*
foreign key (kolomnaam) references tabelnaam(originelekolom);
alter tabel add foreign key (kolomnaam) references tabelnaam(originelekolom);
on delete, on update	# wat gebeurt er als PK wijzigen de integriteit van FK schendt?
	restrict	# actie wordt geweigerd (default)
	cascade		# wordt uitgevoerd op tabel en gerelateerde tabel
	set null	# gerelateerde velden worden null
	no action;	# fout wordt genegeerd, integriteit wordt geschonden
create view viewnaam as select ...;	# nieuwe view aanmaken*
create or replace / alter view;	# verander de definitie van een view*
drop view viewnaam	# verwijder een view
```

* aggregatiefunctie: TODO
* index: TODO
	* constraint: TODO
* views: Een nieuwe tabel die gedefinieerd wordt door een bepaalde query

#SQL Joins

![](http://www.codeproject.com/KB/database/Visual_SQL_Joins/Visual_SQL_JOINS_orig.jpg)

# Niveaupeiling

```sql
SELECT brandstof, COUNT(*)
	FROM autos
	INNER JOIN autoinfo ON autos.autoinfo_id=autoinfo.id
	GROUP BY brandstof
	ORDER BY Count(*)
	DESC LIMIT 1;

SELECT COUNT(DISTINCT(autoinfo.bouwjaar)) AS aantal, verkopers.naam
	FROM verkopers
	INNER JOIN autos ON verkopers.id=autos.verkopers_id
	INNER JOIN autoinfo ON autoinfo.id=autos.autoinfo_id
	WHERE verkopers.naam='Katja';

SELECT autos.chassisNR, autoinfo.basisprijs+SUM(opties.prijs) AS verkoopprijs
	FROM opties
	INNER JOIN autos_has_opties ON autos_has_opties.opties_id=opties.id
	INNER JOIN autos ON autos.chassisNR=autos_has_opties.autos_chassisNR
	INNER JOIN autoinfo ON autoinfo.id=autos.autoinfo_id
	GROUP BY autos.chassisNR;
```
