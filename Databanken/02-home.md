# Databanken 1
## Labo 2

Haroen Viaene

```SQL
mysql -u haroen -p < garage.sql
mysql -u haroen -p
SHOW databases;
use garage;
show tables;
+------------------+
| Tables_in_garage |
+------------------+
| autoinfo         |
| autos            |
| autos_has_opties |
| autos_opties     |
| opties           |
| verkopers        |
+------------------+
select * from autos;
+-----------+-------------+--------------+
| chassisNR | autoinfo_id | verkopers_id |
+-----------+-------------+--------------+
|      1234 |           1 |            1 |
|      1578 |           6 |            1 |
|      4589 |           2 |            3 |
|      5286 |           1 |            1 |
|      7895 |           2 |            2 |
|     12478 |           5 |            1 |
|     14147 |           3 |            2 |
+-----------+-------------+--------------+
```

1. Geef van elke verkochte auto, de verkoper die de auto verkocht heeft, samen met het bouwjaar, het merk en het model van de verkochte auto. Sorteer het resultaat eerst op bouwjaar, en daarna op de naam van de verkoper.

	```SQL
	SELECT naam, bouwjaar, merk, model
	FROM autos
	INNER JOIN autoinfo ON autoinfo.id = autos.autoinfo_id
	INNER JOIN verkopers ON verkopers.id = autos.verkopers_id
	ORDER BY bouwjaar, naam ASC;
	```

2. Geef per verkoper het aantal auto’s hij/zij verkocht heeft. Sorteer op het aantal verkochte wagens.

	```SQL
	SELECT naam, COUNT(chassisNR)
	FROM verkopers
	INNER JOIN autos ON autos.verkopers_id = verkopers.id
	GROUP BY verkopers_id
	ORDER BY COUNT(chassisNR) DESC;
	```

3. Hoeveel verschillende merken zijn er verkocht?

	```SQL
	SELECT COUNT(DISTINCT merk) AS 'Aantal merken'
	FROM autoinfo;
	```

4. Geef de totale verkoopprijs van de auto met chassisnr 1234.

	```SQL
	SELECT basisprijs+SUM(prijs)
	FROM autos
	INNER JOIN autoinfo ON autoinfo.id = autos.autoinfo_id
	INNER JOIN autos_opties ON autos_opties.chassisNR = autos.chassisNR
	WHERE autos.chassisNR = 1234;
	```

5. Geef de auto (merk, model, chassisnr, verkoopprijs) die het duurst is. Hou ook rekening met de opties.

	```SQL
	SELECT;
	```
