CREATE DATABASE  IF NOT EXISTS `garage` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `garage`;
-- MySQL dump 10.13  Distrib 5.6.13, for Win32 (x86)
--
-- Host: localhost    Database: garage
-- ------------------------------------------------------
-- Server version	5.6.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `autoinfo`
--

DROP TABLE IF EXISTS `autoinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `autoinfo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `merk` varchar(45) DEFAULT NULL,
  `model` varchar(45) DEFAULT NULL,
  `bouwjaar` int(11) DEFAULT NULL,
  `brandstof` enum('benzine','diesel','lpg','hybrid','elektriciteit') DEFAULT NULL,
  `basisprijs` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `autoinfo`
--

LOCK TABLES `autoinfo` WRITE;
/*!40000 ALTER TABLE `autoinfo` DISABLE KEYS */;
INSERT INTO `autoinfo` VALUES (1,'Ford','Focus',2010,'diesel',19000.00),(2,'Ford','Fiesta',2010,'diesel',11000.00),(3,'Volvo','C30',2010,'diesel',20000.00),(4,'Volvo','C30',2010,'benzine',18000.00),(5,'Ford','Mondeo',2011,'diesel',25000.00),(6,'Ford ','SMax',2012,'diesel',35000.00),(7,'Ford','Kuga',2011,'diesel',30000.00);
/*!40000 ALTER TABLE `autoinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `autos`
--

DROP TABLE IF EXISTS `autos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `autos` (
  `chassisNR` int(11) NOT NULL,
  `autoinfo_id` int(11) NOT NULL,
  `verkopers_id` int(11) NOT NULL,
  PRIMARY KEY (`chassisNR`),
  KEY `fk_autos_autoinfo1` (`autoinfo_id`),
  KEY `fk_autos_verkopers1` (`verkopers_id`),
  CONSTRAINT `fk_autos_autoinfo1` FOREIGN KEY (`autoinfo_id`) REFERENCES `autoinfo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_autos_verkopers1` FOREIGN KEY (`verkopers_id`) REFERENCES `verkopers` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `autos`
--

LOCK TABLES `autos` WRITE;
/*!40000 ALTER TABLE `autos` DISABLE KEYS */;
INSERT INTO `autos` VALUES (1234,1,1),(1578,6,1),(4589,2,3),(5286,1,1),(7895,2,2),(12478,5,1),(14147,3,2);
/*!40000 ALTER TABLE `autos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `autos_has_opties`
--

DROP TABLE IF EXISTS `autos_has_opties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `autos_has_opties` (
  `autos_chassisNR` int(11) NOT NULL,
  `opties_id` int(11) NOT NULL,
  PRIMARY KEY (`autos_chassisNR`,`opties_id`),
  KEY `fk_autos_has_opties_opties1` (`opties_id`),
  KEY `fk_autos_has_opties_autos1` (`autos_chassisNR`),
  CONSTRAINT `fk_autos_has_opties_autos1` FOREIGN KEY (`autos_chassisNR`) REFERENCES `autos` (`chassisNR`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_autos_has_opties_opties1` FOREIGN KEY (`opties_id`) REFERENCES `opties` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `autos_has_opties`
--

LOCK TABLES `autos_has_opties` WRITE;
/*!40000 ALTER TABLE `autos_has_opties` DISABLE KEYS */;
INSERT INTO `autos_has_opties` VALUES (1234,1),(12478,1),(1234,2),(4589,2),(12478,2),(1234,3),(12478,3),(4589,4),(12478,4),(1578,5);
/*!40000 ALTER TABLE `autos_has_opties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `autos_opties`
--

DROP TABLE IF EXISTS `autos_opties`;
/*!50001 DROP VIEW IF EXISTS `autos_opties`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `autos_opties` (
  `chassisNR` tinyint NOT NULL,
  `naam` tinyint NOT NULL,
  `prijs` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `opties`
--

DROP TABLE IF EXISTS `opties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `opties` (
  `id` int(11) NOT NULL,
  `naam` varchar(45) DEFAULT NULL,
  `prijs` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `opties`
--

LOCK TABLES `opties` WRITE;
/*!40000 ALTER TABLE `opties` DISABLE KEYS */;
INSERT INTO `opties` VALUES (1,'airco',1000.00),(2,'gps',1000.00),(3,'verwarmde buitenspiegels',500.00),(4,'automaat',2000.00),(5,'automatten',200.00),(6,'verwarmde zetels',1000.00);
/*!40000 ALTER TABLE `opties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `verkopers`
--

DROP TABLE IF EXISTS `verkopers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `verkopers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `naam` varchar(45) DEFAULT NULL,
  `adres` varchar(45) DEFAULT NULL,
  `provincie` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `verkopers`
--

LOCK TABLES `verkopers` WRITE;
/*!40000 ALTER TABLE `verkopers` DISABLE KEYS */;
INSERT INTO `verkopers` VALUES (1,'Peter','Gent','Oost-Vlaanderen'),(2,'Bram','Deinze','Oost-Vlaanderen'),(3,'Katja','Mechelen','Antwerpen'),(4,'Elio','Bergen','Henegouwen');
/*!40000 ALTER TABLE `verkopers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Final view structure for view `autos_opties`
--

/*!50001 DROP TABLE IF EXISTS `autos_opties`*/;
/*!50001 DROP VIEW IF EXISTS `autos_opties`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `autos_opties` AS select `autos`.`chassisNR` AS `chassisNR`,`opties`.`naam` AS `naam`,`opties`.`prijs` AS `prijs` from (((`autos` join `autoinfo` on((`autos`.`autoinfo_id` = `autoinfo`.`id`))) join `autos_has_opties` on((`autos`.`chassisNR` = `autos_has_opties`.`autos_chassisNR`))) join `opties` on((`autos_has_opties`.`opties_id` = `opties`.`id`))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-06-10  9:10:40
