<?php

/**
 * Lab 03, Exercise 1 — Start file
 * @author Bramus Van Damme & Joris Maervoet <joris.maervoet@odisee.be>
 */

	// Set language to Dutch
	setlocale(LC_ALL, 'Dutch_Netherlands');

	// Create a timestamp for the date
	$timestamp = new DateTime('1983-12-26 11:45:00',new DateTimeZone('Europe/Brussels'));

	// Output
	try {
		echo $timestamp->getTimeStamp() . '<br />';					// timestamp
		echo $timestamp->format('F') . '<br />';		// Month (in words)
		echo $timestamp->format('l') . '<br />';		// Day of week (in words)
		echo $timestamp->format('D') . '<br />';		// Day of week (short, in words)
		echo $timestamp->format('dmY') . '<br />';	// Date as "26121983"
		echo $timestamp->format('ymd') . '<br />';	// Date as "831226"
		echo $timestamp->format('g:i A') . '<br />';	// Date as "11:45 AM"
		echo $timestamp->format('t') . '<br />';		// Number of days in given month
		echo $timestamp->format('j F Y') . '<br />';	// Date as "26 december 1983" (*)
		echo $timestamp->format('W') . '<br />';		// Weeknumber of date
	} catch(Exception $ex) {
		echo ('The time of this script could not be interpreted as a date.');
	}
// EOF