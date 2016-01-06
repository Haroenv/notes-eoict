DROP DATABASE IF EXISTS `todo`;
CREATE DATABASE `todo` DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_unicode_ci;
USE `todo`;

CREATE TABLE `todolist` (
  `id` int(11) NOT NULL auto_increment,
  `what` varchar(255) NOT NULL,
  `priority` enum('high','normal','low') NOT NULL,
  `added_on` datetime NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_unicode_ci AUTO_INCREMENT = 4;

--
-- Dumping data for table `todolist`
--

INSERT INTO `todolist` VALUES (1, 'A very urgent task', 'high', now());
INSERT INTO `todolist` VALUES (2, 'A normal task', 'normal', now());
INSERT INTO `todolist` VALUES (3, 'A non-important task', 'low', now());