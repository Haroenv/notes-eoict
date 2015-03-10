Databases 3.
============

Haroen Viaene

1. Hoeveel artikelen zijn nooit besteld? Maak hiervoor gebruik van subqueries.

    ```SQL
    SELECT COUNT(artikelen.artikel_id)
    FROM artikelen
    WHERE artikel_id NOT IN
        (
        SELECT artikel_id
        FROM items
        )
    ;
    ```

2. Wat is de totale waarde van de bestellingen die geplaatst zijn in de maand januari?

    ```SQL
    SELECT SUM(prijs*aantal) AS waarde
    FROM artikelen
    INNER JOIN items ON items.artikel_id = artikelen.artikel_id
    INNER JOIN bestellingen ON bestellingen.bestelling_id = items.bestelling_id
    WHERE MONTH(datum) = 1;
    ```

3. Welke klanten hebben nog geen bestellingen gedaan? Schrijf op 2 manieren, d.w.z. met subquery en zonder subquery.

    met subquery:

    ```SQL
    SELECT naam,vnaam
    FROM klanten
    WHERE klant_id NOT IN
        (
        SELECT klant_id
        FROM bestellingen
        )
    ;
    ```

    zonder subquery:

    ```SQL
    SELECT naam,vnaam
    FROM klanten
    LEFT JOIN bestellingen ON bestellingen.klant_id=klanten.klant_id
    WHERE bestellingen.klant_id IS NULL;
    ```

4. Geef de top-3 van gemeenten berekend volgens aantal bestellingen door klanten uit die gemeente.

    ```SQL
    SELECT gemeente, COUNT(gemeente) AS bestellingen
    FROM bestellingen
    INNER JOIN klanten on klanten.klant_id = bestellingen.klant_id
    GROUP BY gemeente
    ORDER BY COUNT(gemeente) DESC
    LIMIT 3;
    ```
