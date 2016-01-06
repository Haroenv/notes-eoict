<?php

	// includes
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'includes' . DIRECTORY_SEPARATOR . 'classes' . DIRECTORY_SEPARATOR . 'template.php';
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'includes' . DIRECTORY_SEPARATOR . 'classes' . DIRECTORY_SEPARATOR . 'datalayer.php';

	// datalayer
	$db = new DataLayer();

	// retrieve contacts
	$contacts = $db->getContacts();

	// build template
	$tpl = new Template(__DIR__  . DIRECTORY_SEPARATOR . 'templates' . DIRECTORY_SEPARATOR . 'browse.tpl');

	// parse contacts
	$tpl->setIteration('iContacts');
	foreach ($contacts as $contact) {
		$tpl->assignIteration('id', $contact->id);
		$tpl->assignIteration('name', $contact->name);
		$tpl->assignIteration('email', $contact->email);
		$tpl->assignIteration('role', $contact->role);
		$tpl->assignIteration('comments', $contact->comments);
		$tpl->assignIteration('searchstring', $contact->name . ' ' . $contact->email . ' '. $contact->role . ' ' . $contact->comments);
		$tpl->refillIteration();
	}
	$tpl->parseIteration('iContacts');

	// display
	$tpl->display();


?>