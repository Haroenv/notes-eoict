-- phpMyAdmin SQL Dump
-- version 3.1.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 09, 2010 at 02:11 PM
-- Server version: 5.1.37
-- PHP Version: 5.2.10

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `ria_project_2010`
--

-- --------------------------------------------------------

--
-- Table structure for table `contacts`
--

DROP TABLE IF EXISTS `contacts`;

CREATE TABLE IF NOT EXISTS `contacts` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `role` varchar(100) NOT NULL,
  `comments` text NOT NULL,
  `sortorder` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `order` (`sortorder`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=40 ;

--
-- Dumping data for table `contacts`
--

INSERT INTO `contacts` (`id`, `name`, `email`, `role`, `comments`, `sortorder`) VALUES
(30, 'Christophe Van Laere', 'cvl@skynet.be', 'friend', 'dit is een testcommentaar', 5),
(31, 'Sara De Jaeger', 'sara.de.jaeger@cera.be', 'friend', '', 6),
(32, 'Birgit Beutels', 'bbeutels@combell.co.uk', 'other', '', 7),
(33, 'Hans Gruyaert', 'hans.gruyaert@kahosl.be', 'colleague', '', 8),
(34, 'Frank Haelman', 'frank.haelman@kahosl.be', 'colleague', '', 9),
(35, 'Kristien Costermans', 'kcostermans@fingov.be', 'friend', '', 10),
(36, 'Jan Mulle', 'jantje@pruimenboom.be', 'other', '', 11),
(37, 'Tristan Lejeune', 'tlejeun@telenet.be', 'family', 'dit is een testcommentaar', 12),
(38, 'Isadora Dang', 'isadora.dang@telenet.be', 'friend', '', 13),
(39, 'Bram Van Damme', 'bramus.vandamme@kahosl.be', 'colleague', 'collega webtechnieken', 14),
(40, 'Rogier van der Linde', 'rogier.vanderlinde@kahosl.be', 'other', 'dit ben ik zelf', 15);
