<?php
	/**
	 * Start of the name
	 */
	define('START', 7);

	$query = $argv[1];
	$file = file('php://stdin');

	// echo print_r($file);

	/**
	 * @param  string the line to inspect
	 * @param  string the query to check for
	 * @return string the owner of a certain plate or the plate of a certain owner containing the search string
	 */
	function inspectLine($line,$query) {
		$pos = stripos($line,$query);
		if ($pos !== false) {
			if ($pos < START) {
				return substr($line, 0, START - 1) . ' is the plate of ' . trim(substr($line, START)) . PHP_EOL;
			} else {
				return trim(substr($line, START)) . ' is the owner of ' . substr($line, 0, START - 1). PHP_EOL;
			}
		};
	}

	/**
	 * Do inspectLine for each line of the file
	 */
	for ($i=0; $i < count($file); $i++) {
		echo inspectLine($file[$i],$query);
	}

 ?>