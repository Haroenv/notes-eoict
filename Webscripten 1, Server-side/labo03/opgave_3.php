<?php

/**
 * Lab 03, Exercise 3 & 4 — Start File
 * @author Bramus Van Damme <bramus.vandamme@odisee.be>
 */

	// vars

		$basePath = __DIR__ . DIRECTORY_SEPARATOR . 'images'; // C:\wamp\www\vn.an\labo03\images
		$baseUrl = 'images'; // images
		$images = array(); // An array which will hold all our images
		$lines = new SPLFileObject($basePath . DIRECTORY_SEPARATOR . 'captions.txt');

	// Main code

		// @TODO Open directory and captions file using some SPL classes
    $di = new DirectoryIterator($basePath);

		// @TODO loop directory
    foreach ($di as $file) {

        // exclude . and .. + we don't want directories
        if (!$file->isDot() && !$file->isDir()) {

					// If it's a '.jpg', add it onto an array named $images
					// Use an associative array so you can store the filename, and caption
        	if ($file->getExtension() === 'jpg') {
        		$images [] = array('url'=> $baseUrl . DIRECTORY_SEPARATOR . $file, 'caption' => $lines->current());
        		$lines->next();
					}
        }
    }

?><!doctype html>
<html>
<head>
	<title>Images</title>
	<meta charset="utf-8" />
	<style>

		body {
			font-family: "HelveticaNeue-Light", "Helvetica Neue Light", "Helvetica Neue", sans-serif;
			font-weight: 300;
			font-size: 14px;
			line-height: 1.2;
			background: #FCFCFC;
		}

		ul {
			margin: 0;
			padding: 0;
			list-style: none;
		}

		li {
			display:  block;
			width: 310px;
			height: 310px;
			float: left;
			border: 1px solid #ccc;
			margin: 20px;
			position: relative;
			box-shadow: 0 0 20px #CCC;

		}

		li img {
			max-width: 100%;
		}

		li .caption {
			display: block;
			position: absolute;
			bottom: 0;
			left: 0;
			right: 0;
			padding: 5px;
			color: #000;
			background: rgba(255,255,255,0.9);
			border-top: 1px solid #ccc;
			text-shadow: 1px 1px 1px #fff;
		}

		li:hover {
			box-shadow: 0 0 20px #999;
		}

	</style>
</head>
<body>
	<ul>
<?php
	foreach ($images as $image) {
		echo '		<li><img src="' . $image['url'] . '"></img><span class="caption">' . $image['caption'] . '</span></li>' . PHP_EOL;
	}
?>
	</ul>
</body>
</html>