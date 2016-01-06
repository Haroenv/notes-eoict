<?php
	/**
	 * Encrypts a string using $shift Caesar Cipher
	 * @param string $string The string that will be encrypted
	 * @param string $shift the amount of characters shifted
	 * @return The encrypted string
	 */
	function encryptString($string,$shift) {
		for ($i = 0; $i < strlen($string); $i++) {
			$string[$i] = chr(ord($string[$i]) + $shift);
		}
		return $string . PHP_EOL;
	}

	$plates = file('php://stdin');
	print_r($plates);

	for ($i = 0; $i < count($plates); $i++) {
		echo encryptString($plates[$i],3);
	}
 ?>