##############################################
# Oefeningencursus Gegevensbanken
# Relationele Databases
#
# BIBLIO DATABASE
#
# @author: Vakgroep ICT
#
##############################################

# kijken of de biblio database reeds bestaat - drop - aanmaken


# de biblio database gebruiken


# tabel bezoekers aanmaken


# tabel uitgeverijen aanmaken


# tabel boekinfo aanmaken


# tabel boeken aanmaken


# tabel ontleningen aanmaken


# data invoegen voor bezoekers
insert into bezoekers(naam, leeftijd) values
  ('Smith John', 34),
  ('Garcia Jane', 22),
  ('Davis David', 45),
  ('Williams Lois', 29),
  ('Dunn Julie', 54),
  ('Lloyd Christopher', 18);

# data invoegen voor uitgeverijen
insert into uitgeverijen(naam, website) values
  ('apress', 'http://www.apress.com'),
  ('O\'Reilly', 'http://www.oreilly.com'),
  ('Sybex', 'http://www.sybex.com'),
  ('Wrox', 'http://www.wrox.com'),
  ('Sams', 'http://www.samspublishing.com'),
  ('Prentice Hall', 'http://www.prenticehall.com'),
  ('Addison Wesley', 'http://www.awprofessional.com');

# data invoegen voor boekinfo
insert into boekinfo(isbn, titel, jaar, uitgeverij_id) values
  ('0-7821-4162-5', 'Mastering MySQL 4', '2003', 3),
  ('1-59059-535-1', 'The Definitive Guide to MySQL 5', '2005', 1),
  ('1-861006-92-6', 'Beginning Databases with MySQL', '2002', 4),
  ('1-56592-744-3', 'SQL in a nutshell', '2001', 2),
  ('1-56592-846-6', 'Practical PostgreSQL', '2002', 2),
  ('1-59059-332-4', 'Beginning MySQL Database Design and Optimization', '2004', 1),
  ('0-201-68419-5', 'An Introduction to Database Systems', '2000', 7),
  ('90-430-0842-7', 'Databases', '2004', 8);

# data invoegen voor boeken
insert into boeken(boek_id, isbn) values
  (null, '0-7821-4162-5'),
  (null, '0-7821-4162-5'),
  (null, '1-59059-535-1'),
  (null, '1-861006-92-6'),
  (null, '1-56592-744-3'),
  (null, '1-56592-846-6'),
  (null, '1-56592-846-6'),
  (null, '1-56592-846-6'),
  (null, '1-59059-332-5'),
  (null, '0-201-68419-5'),
  (null, '90-430-0842-7');

# data invoegen voor ontleningen
insert into ontleningen(bezoeker_id, boek_id, ontleendatum) values
  (1, 1, '2006-08-20'),
  (2, 2, '2006-08-21'),
  (3, 3, '2006-08-21'),
  (1, 1, '2006-08-21'),
  (4, 4, '2006-08-22'),
  (1, 5, '2006-08-24'),
  (5, 1, '2006-08-25'),
  (3, 11, '2006-08-25'),
  (3, 2, '2006-08-25'),
  (6, 7, '2006-08-25'),
  (1, 8, '2006-08-25'),
  (4, 4, '2006-08-26');