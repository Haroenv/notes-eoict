##############################################
# Oefeningencursus Gegevensbanken
# Inleiding
#
# POSTORDER DATABASE
#
# @author: Vakgroep ICT
# 
##############################################

# de postorder database aanmaken
drop database if exists postorder;
create database postorder;
use postorder;

# tabel klanten aanmaken
create table klanten (
	klant_id int not null auto_increment, 
	naam varchar(40) not null, 
	vnaam varchar(20) not null, 
	adres varchar(50) not null, 
	gemeente varchar(25) not null, 
	primary key (klant_id)
) engine='innodb';

# tabel artikelen aanmaken
create table artikelen (
	artikel_id int not null auto_increment, 
	beschr varchar(60) not null,
	voorraad smallint not null default 0,
	eenheid	varchar(20) not null,
	prijs decimal(5,2) not null, 	
	primary key (artikel_id)
) engine='innodb';

# tabel bestellingen aanmaken
create table bestellingen (
	bestelling_id int not null auto_increment,
	klant_id int not null,
	datum date not null,
	primary key (bestelling_id),
	index (klant_id),
	foreign key (klant_id) references klanten(klant_id)
) engine='innodb';

# tabel items aanmaken
create table items (	
	bestelling_id int not null,
	artikel_id int not null, 
	aantal int not null,
	tijdstip datetime default null,
	primary key (bestelling_id, artikel_id),
	index (bestelling_id),
	foreign key (bestelling_id) references bestellingen(bestelling_id),
	index (artikel_id),
	foreign key (artikel_id) references artikelen(artikel_id)
) engine='innodb';

# data toevoegen: tabel klantenen
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN BELLE','WERNER','HUNDELGEMSE STEENWEG, 105','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('HOLLANDS','MICHEL','LEENWEG, 15','WACHTEBEKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE GRAEVE','LIEVEN','GUIDE GEZELLELAAN, 95','DEINZE');
insert into klanten(naam, vnaam, adres, gemeente) values ('MAENHOUT','FREDDY','KESSELAARSTRAAT, 5','KAPRIJKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE LANGHE','JO','VAN AKENSTRAAT, 13','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('LAROY','JAN','GANZENDRIES, 231','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('LAMBERT','MAURICE','ZWIJNAARDESTEENWEG, 133','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('GOOSENS','CARLOS','BALGERHOEKJE, 154','EEKLO');
insert into klanten(naam, vnaam, adres, gemeente) values ('GOVAERT','BERT','DONKLAAN, 17','BERLARE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VERHELLEN','STEFAAN','BREDERODESTRAAT, 15','MELLE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DEWULF','JOZEF','KERKSTRAAT, 66','OLSENE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE VEIRMAN','MIA','HAMSTRAAT, 15','WETTEREN');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE ROO','GRETA','WESTSTRAAT, 54','SLEIDINGE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE COSTER','PATRICK','VANDENBROECKSTRAAT, 40','OSSTAKKER');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE BOEVER','MARIA','BAAIGEMSTRAAT, 387','GAVERE');
insert into klanten(naam, vnaam, adres, gemeente) values ('COSYNS','LUC','TWEEKERKENSTRAAT, 132','ZOTTEGEM');
insert into klanten(naam, vnaam, adres, gemeente) values ('BOONE','ERIK','WALPOORTSTRAAT, 4','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('WILLEMS','BETTY','STOEPESTRAAT, 41','ERTVELDE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VERMAERCKE','KAREL','STATIONSTRAAT, 130','EKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VERMEIREN','JACOB','WEVERBOSLAAN, 44','GENTBRUGGE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN WIJNSBERGHE','MICHEL','OSSTHOEK, 22B','LEMBERGE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VANHAUTE','ERIK','NAZARETHSESTEENWEG, 49','DEINZE');
insert into klanten(naam, vnaam, adres, gemeente) values ('MAES','FERDINAND','MECHELSESTRAAT, 24','LONDERZEEL');
insert into klanten(naam, vnaam, adres, gemeente) values ('LEFEVRE','JEANNE','WELVAARTSRTAAT, 48','AALST');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE TAEYE','TANJA','ZWIJNAARDSESTWG, 100B','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE LEENHEER','JOHN','OMMEGANGSTRAAT, 35','ZELE');
insert into klanten(naam, vnaam, adres, gemeente) values ('EVERAERT','CLARA','MOLENSTRAAT, 62','MELDERT');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE TAYE','WALTER','BOTERMELKSTRAAT, 3','ONKERZELE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE TROYER','AN','BOSVELD, 18','DENDERWINDEKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DERIEMAEKER','EDOUARD','ZONNESTRAAT, 17','RONSE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE SADELEER','BANJAMIN','BOSKOUTERLAAN, 21','ERPE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE LANGHE','JO','STATIONSTRAAT, 11','OUDENAARDE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE BILDE','ANTOON','HEIRSTRAAT, 118','DENDERMONDE');
insert into klanten(naam, vnaam, adres, gemeente) values ('BORGHMANS','HERMAN','HOPMARKT, 30','AALST');
insert into klanten(naam, vnaam, adres, gemeente) values ('VERLEYEN','MARK','DROPSTRAAT, 6','AALTER');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN WESEMAEL','KURT','STEENSTRAAT, 72','LEDE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN WAEYENBERGHE','FREDERICK','GENTSTRAAT, 51','GERAARDSBERGEN');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN WIJNSBERGHE','ACHIEL','BRUSSELSESTEENWEG, 120','LEBEKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN HAVERBEKE','HARRY','BRUSSELSESTEENWEG, 147','AALTER');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN HAUWERMEIREN','JAN','ASTRIDPLEIN, 8','LEBEKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN DER PERRE','WIM','KOUTERSTRAAT, 9','AALST');
insert into klanten(naam, vnaam, adres, gemeente) values ('VANDERSNICK','ANN','PIETER HEIRMANSHOEK, 6','BERLARE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN DEN BOSSCHE','WALTER','VOORUITZICHTSTRAAT, 83','AALST');
insert into klanten(naam, vnaam, adres, gemeente) values ('DE CORTE','JO','TER PLATEN, 5','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('VERMAERKE','JOHAN','PONTSTRAAT, 72','DEINZE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VANDEKERKHOVE','MARC','SMIDSESTRAAT, 58','GENT');
insert into klanten(naam, vnaam, adres, gemeente) values ('GIJSSENS','STEVEN','MULLEMSTRAAT, 6','TERNAT');
insert into klanten(naam, vnaam, adres, gemeente) values ('OPSTAELE','HANS','ZELLICKLAAN, 24','OOSTENDE');
insert into klanten(naam, vnaam, adres, gemeente) values ('DEVOS','WOUTER','STATIONSSTRAAT, 17','OOSTROZEBEKE');
insert into klanten(naam, vnaam, adres, gemeente) values ('VAN DE VELDE','GEERT','VEERSTRAAT, 84A','UITBERGEN');

# data toevoegen: tabel artikelen
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bord 26cm',20,'stuk',3.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bord 31cm',20,'stuk',4.2);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bordje 22cm',20,'stuk',2.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bierglas 26cl',12,'set van 2',7.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('wijnglas 10cl',12,'set van 2',7);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('wijnglas 16cl',12,'set van 2',7.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('glas 25cl',24,'set van 12',5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bestek chroomstaal',10,'set 24-delig',35);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('eetservies in aardewerk',10,'set 18-delig',12.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('beker in aardewerk',10,'set van 8',3.7);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('afdruiprek in grenen',5,'stuk',5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bestek roestvrij staal',5,'set 3-delig',12.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bestek roestvrij staal',5,'set 16-delig',35);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bestek roestvrij staal',5,'set 16-delig',25);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('wijnglas 19cl',7,'set van 12',5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('eetservies 4 persoons',5,'set 40-delig',25);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('serverbord messing 30cm',0,'stuk',10);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kandelaar 5-armig',3,'stuk',35);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kaarslantaarn glas',0,'stuk',7.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kaarsen 28cm',50,'set van 10',3.8);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('waxinelichtje',50,'set van 30',1.7);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('vaas geglazuurd 13cm',15,'stuk',7);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('vaas geglazuurd 29cm',0,'stuk',7.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('klok A1 en glas 39cm',5,'stuk',25);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('klok golfkarton 28cm',5,'stuk',3.7);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lijst hout/glas 40x50cm',5,'stuk',20);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lijst ijzer/glas 10x15cm',5,'stuk',5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lijst grenen 10x15cm',5,'stuk',3.7);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lijst grenen 30x40cm',5,'stuk',8.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lijst grenen 50x70cm',5,'stuk',17.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('spiegel 75x75cm',2,'stuk',47);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('spiegel 8-hoek 25cm',2,'stuk',15);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('spiegel 45x60cm',3,'set van 4',27.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kapstok metaal staand',4,'stuk',32.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kapstok grenen 90x30x26cm',4,'stuk',27.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kapstok grenen 78x27x19cm',1,'stuk',35);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lamp bol 26cm 60W',6,'stuk',12.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('lamp wand 10x30cm TL',6,'stuk',22.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('tafellamp 46cm 40W',6,'stuk',32.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('kroonluchter 56cm 5x40W',2,'stuk',70);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('wandlamp 2x40W',2,'stuk',25);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('bureaulamp halogeen 20W',7,'stuk',7.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('hanglamp 3x40W',2,'stuk',45);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('inbouwlamp halogeen 20W',10,'set van 2',30);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('deurmat kokos 40x60cm',11,'stuk',2.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('ronde mat maisblad 90cm',5,'stuk',10);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('mat maisblad 120x180cm',2,'stuk',25);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('mat maisblad 150x240cm',5,'stuk',37.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('mat kokos 85x250cm',5,'stuk',32.5);
insert into artikelen(beschr, voorraad, eenheid, prijs) values ('mat kokos 140x200cm',5,'stuk',40);

# data toevoegen: tabel bestellingen
insert into bestellingen values (1, 1, '2005-10-06');
insert into bestellingen values (2, 2, '2005-10-06');
insert into bestellingen values (3, 20, '2005-10-07');
insert into bestellingen values (4, 10, '2005-10-07');
insert into bestellingen values (5, 7, '2005-10-09');
insert into bestellingen values (6, 1, '2005-10-10');
insert into bestellingen values (7, 2, '2005-10-11');
insert into bestellingen values (8, 24, '2005-10-11');
insert into bestellingen values (9, 15, '2005-10-14');
insert into bestellingen values (10, 10, '2005-10-14');
insert into bestellingen values (11, 1, '2005-10-16');
insert into bestellingen values (12, 5, '2005-10-16');
insert into bestellingen values (13, 21, '2005-10-17');
insert into bestellingen values (14, 10, '2005-10-18');
insert into bestellingen values (15, 7, '2005-10-21');
insert into bestellingen values (16, 1, '2005-10-23');
insert into bestellingen values (17, 2, '2005-10-24');
insert into bestellingen values (18, 21, '2005-10-25');
insert into bestellingen values (19, 16, '2005-10-29');
insert into bestellingen values (20, 16, '2005-10-31');
insert into bestellingen values (21, 11, '2005-11-05');
insert into bestellingen values (22, 12, '2005-11-07');
insert into bestellingen values (23, 30, '2005-11-09');
insert into bestellingen values (24, 31, '2005-11-09');
insert into bestellingen values (25, 27, '2005-11-09');
insert into bestellingen values (26, 21, '2005-11-14');
insert into bestellingen values (27, 26, '2005-11-16');
insert into bestellingen values (28, 42, '2005-11-18');
insert into bestellingen values (29, 45, '2005-11-21');
insert into bestellingen values (30, 50, '2005-11-21');

# data toevoegen: tabel items
insert into items values (1, 2, 6, '2005-10-08 09:15:00');
insert into items values (1, 7, 1, '2005-10-08 09:15:00');
insert into items values (2, 26, 2, '2005-10-08 14:15:00');
insert into items values (3, 35, 1, '2005-10-09 10:05:00');
insert into items values (3, 43, 2, '2005-10-09 10:05:00');
insert into items values (4, 42, 1, '2005-10-09 14:25:00');
insert into items values (5, 35, 2, '2005-10-12 11:05:00');
insert into items values (6, 4, 3, '2005-10-14 16:10:00');
insert into items values (6, 16, 1, '2005-10-14 16:10:00');
insert into items values (7, 25, 1, '2005-10-14 16:10:00');
insert into items values (8, 39, 1, '2005-10-15 15:55:00');
insert into items values (9, 13, 1, '2005-10-15 16:40:00');
insert into items values (10, 16, 2, '2005-10-15 17:35:00');
insert into items values (10, 17, 1, '2005-10-15 17:35:00');
insert into items values (10, 21, 1, '2005-10-21 09:35:00');
insert into items values (12, 40, 1, '2005-10-21 10:15:00');
insert into items values (13, 5, 6, '2005-10-23 13:25:00');
insert into items values (14, 49, 3, '2005-10-23 13:45:00');
insert into items values (15, 25, 1, '2005-10-23 14:10:00');
insert into items values (15, 26, 3, '2005-10-23 14:10:00');
insert into items values (16, 39, 1, '2005-10-25 15:45:00');
insert into items values (17, 22, 1, '2005-10-29 11:50:00');
insert into items values (18, 10, 1, '2005-10-29 12:45:00');
insert into items values (19, 18, 1, '2005-11-01 09:10:00');
insert into items values (19, 20, 4, '2005-11-03 13:05:00');
insert into items values (19, 47, 2, '2005-11-03 13:05:00');
insert into items values (20, 37, 2, '2005-11-04 09:40:00');
insert into items values (21, 22, 1, '2005-11-06 14:10:00');
insert into items values (21, 23, 1, NULL);
insert into items values (22, 44, 3, '2005-11-12 10:20:00');
insert into items values (23, 30, 2, '2005-11-12 11:05:00');
insert into items values (24, 18, 1, '2005-11-12 13:35:00');
insert into items values (25, 43, 1, '2005-11-14 17:10:00');
insert into items values (26, 16, 2, '2005-11-19 09:40:00');
insert into items values (27, 16, 1, '2005-11-21 10:45:00');
insert into items values (28, 19, 1, NULL);
insert into items values (29, 17, 1, NULL);
insert into items values (29, 36, 2, NULL);
insert into items values (29, 47, 3, NULL);
insert into items values (30, 7, 1, NULL);
insert into items values (30, 13, 1, NULL);

# stored procedure waarmee de velden datum en tijdstip uit bestellingen en items kunnen geactualiseerd worden
drop procedure if exists perform_updates;

delimiter //

create procedure perform_updates()
begin
  declare maximum date;
  declare diff int;
  select max(datum) from bestellingen into maximum;
  select to_days(curdate()) - to_days(maximum) into diff;
  update bestellingen set datum = adddate(datum, interval diff day); 
  update items set tijdstip = adddate(tijdstip, interval diff day);
end
//

delimiter ;

call perform_updates();



