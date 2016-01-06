<?php

	/**
	 * Handles error messages
	 *
	 * @param string $message
	 * @param string $type
	 * @return void
	 */
	function showError($message, $type = 'general') {
		// log error
		file_put_contents(ERROR_LOG, '[' . strtoupper($type) .'] ' . date("Y-m-d H:i:s") . ' ' . $message . "\n", FILE_APPEND);

		// debug mode: show the error
		if (DEBUG === true) {
			die($message);
		} 

		// production mode: redirect to an error page
		else {
			header('location: error.php');
		}

		// halt script
		exit();
	}

	/**
	 * Handles image rescales
	 *
	 * @param string $photoPath
	 * @param string $maxW
	 * @param string[optional] $maxH
	 * @param string[optional] $quality
	 * @return void
	 */
	function boxScaleJpg($photoPath, $maxW, $maxH = -1, $quality = 90) {
		$photo    = imagecreatefromjpeg($photoPath);
		$photoW   = imagesx($photo);
		$photoH   = imagesy($photo);
		if ($photoW/$maxW > $photoH/$maxH) {
			$newW = $maxW;
			$newH = $photoH * $maxW/$photoW;
		} else {
			$newH = $maxH;
			$newW = $photoW * $maxH/$photoH;
		}
		$newPhoto = imagecreatetruecolor($newW, $newH);
		imagecopyresampled($newPhoto, $photo, 0, 0, 0, 0, $newW, $newH, $photoW, $photoH);
		imagejpeg($newPhoto, $photoPath, $quality);
		imagedestroy($photo);
		imagedestroy($newPhoto);
	}

// EOF