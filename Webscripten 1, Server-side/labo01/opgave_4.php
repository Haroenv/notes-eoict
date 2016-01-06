<?php
	date_default_timezone_set('Europe/Brussels');
	$input = date_create($argv[1]);
	echo 'De timestamp die de datum representeert:	' . date_format($input,'U') . PHP_EOL;
	echo 'De naam van de maand (in woorden):		' . date_format($input,'M') . PHP_EOL;
	echo 'De dag van de week (in woorden):		' . date_format($input,'l') . PHP_EOL;
	echo 'De dag van de week (kort, in woorden):		' . date_format($input,'D') . PHP_EOL;
	echo 'De datum als “26121983”:			' . date_format($input,'dmY') . PHP_EOL;
	echo 'De datum als “831226”:				' . date_format($input,'ymd') . PHP_EOL;
	echo 'De datum als “11:45 AM”:			' . date_format($input,'h:i A') . PHP_EOL;
	echo 'Het aantal dagen van die maand:			' . date_format($input,'t') . PHP_EOL;
	echo 'De datum als “26 december, 1983”:		' . date_format($input,'d l, Y') . PHP_EOL;
	echo 'weeknummer:					' . date_format($input,'W') . PHP_EOL;
 ?>