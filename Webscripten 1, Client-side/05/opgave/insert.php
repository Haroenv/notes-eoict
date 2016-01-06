<?php

	// includes
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'includes' . DIRECTORY_SEPARATOR . 'classes' . DIRECTORY_SEPARATOR . 'template.php';
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'includes' . DIRECTORY_SEPARATOR . 'classes' . DIRECTORY_SEPARATOR . 'datalayer.php';

	// datalayer
	$db = new DataLayer();

	// actions
	if (isset($_REQUEST['btnCancel'])) {
		header("Location: browse.php");
		exit(0);
	}
	if (isset($_REQUEST['btnOk'])) {
		$newContact = new Contact();
		$newContact->name = $_POST['name'];
		$newContact->email = $_POST['email'];
		$newContact->role = $_POST['role'];
		$newContact->comments = $_POST['comments'];
		$newId = $db->insertContact($newContact);
		if ($_FILES['picture']['tmp_name'] != "") {
			// upload picture
			$copyTo = __DIR__ . '/files/avatars/avatar_' . $newId . '.jpg';
			$copyFrom = $_FILES['picture']['tmp_name'];
			move_uploaded_file($copyFrom, $copyTo);
			boxScaleJpg($copyTo, 100, 70);
		} else {
			$copyTo = __DIR__ . '/files/avatars/avatar_' . $newId . '.jpg';
			$copyFrom = __DIR__ . '/files/avatars/no_thn.jpg';
			copy($copyFrom, $copyTo);
		}
		header("Location: browse.php");
		exit(0);
	}

	// build template
	$tpl = new Template(__DIR__  . DIRECTORY_SEPARATOR . 'templates' . DIRECTORY_SEPARATOR . 'insert.tpl');

	// display
	$tpl->display();

?>