<?php
	/**
	 * Array operations
	 */

	$alphabet = array();

	/**
	 * Add lowercase alphabet to $alphabet in array
	 */
	for ($i=0; $i < 26; $i++) {
		$alphabet[$i] = chr(97 + $i);
	}

	for ($i=0; $i < 26; $i++) {
		echo $i + 1 . $alphabet[$i];
	}

	echo PHP_EOL;

	/**
	 * Print csv version
	 */
	echo implode(', ', $alphabet) . PHP_EOL;

	/**
	 * Show first element of $alphabet, show $alphabet length.
	 * Remove that element, show the length of $alphabet
	 */
	echo count($alphabet);
	echo array_shift($alphabet);
	echo count($alphabet) . PHP_EOL;

	/**
	 * New array cities with their key the zip code
	 */
	$cities = array(9000 => 'Gent', 1000 => 'Brussel', 8500 => 'Kortrijk', 9160 => 'Lokeren');

	/**
	 * get the keys (zip codes) of $cities and put it in $zips
	 */
	$zips = array_keys($cities);

	var_dump($zips);

	echo array_sum($zips) . PHP_EOL;

	/**
	 * Sort $cities alphabetically on value
	 */
	asort($cities);
	echo var_dump($cities);

	/**
	 * Sort $cities from high to low on key
	 */
	krsort($cities);
	echo var_dump($cities);

	/**
	 * Show the name of each 1000-city (1000,2000,3000 < 10000) if it exists
	 */
	for ($i=1000; $i < 10000; $i += 1000) {
		echo array_key_exists($i,$cities) ? strtoupper($cities[$i]) : '';
	}
 ?>