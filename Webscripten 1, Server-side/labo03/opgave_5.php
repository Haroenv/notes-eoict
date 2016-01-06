<?php

/**
 * Basic file upload example
 * @author Bramus Van Damme <bramus.vandamme@odisee.be>
 */

	// a file was uploaded
	if (isset($_FILES['avatar'])) {

		// get file info
		echo '<p>Uploaded file: ' . $_FILES['avatar']['name'] . '</p>' . PHP_EOL;
		echo '<p>Temp location: ' . $_FILES['avatar']['tmp_name'] . '</p>' . PHP_EOL;
		echo '<p>Size: ' . $_FILES['avatar']['size'] . '</p>' . PHP_EOL;

		// check file extension
		if (!in_array((new SplFileInfo($_FILES['avatar']['name']))->getExtension(), array('jpeg', 'jpg', 'png', 'gif'))) {
			exit('<p>Invalid file extension. Only .jpeg, .jpg, .png or .gif allowed</p>');
		}

		// store file in this folder
		@move_uploaded_file(
			$_FILES['avatar']['tmp_name'],
			__DIR__ . DIRECTORY_SEPARATOR . 'images' . DIRECTORY_SEPARATOR . $_FILES['avatar']['name']
		) or die('<p>Error while saving file in the uploads folder</p>');

		// show image
		echo '<p><img src=' . 'images' . DIRECTORY_SEPARATOR . $_FILES['avatar']['name'] . ' alt="" /><p>';
	}

?>
<!doctype html>
<html>
<head>
	<title>Images</title>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1.0" />
	<style>

		body {
			font-family: "HelveticaNeue-Light", "Helvetica Neue Light", "Helvetica Neue", sans-serif;
			font-weight: 300;
			line-height: 1.2;
			background: #FCFCFC;
		}
	</style>
</head>
<body>
<form action="<?php echo $_SERVER['PHP_SELF'];?>" method="post" enctype="multipart/form-data" >
	<label for="avatar">Image: </label>
	<input type="file" name="avatar" id="avatar" /><br />
	<label for="caption">Caption: </label>
	<input type="text" name="caption" id="caption" /><br />
	<input type="submit" />
</form>
</body>
</html>