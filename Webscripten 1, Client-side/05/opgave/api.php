<?php

	// includes
	require_once __DIR__ . DIRECTORY_SEPARATOR . 'includes' . DIRECTORY_SEPARATOR . 'classes' . DIRECTORY_SEPARATOR . 'datalayer.php';

	// datalayer
	$db = new DataLayer();

	// to demonstrate the async aspect
	sleep(1);

	// get vars
	$action = isset($_GET['action']) ? $_GET['action'] : '';

	// all action; unused in this exercise but provided as sample action
	// usage: call api.php?action=all
	if ($action == 'all') {
		// get contacts
		$contacts = $db->getContacts();

		// send to client
		exit(json_encode(array(
			'contacts' => $contacts,
			'status' => 200,
			'message' => 'delete OK'
		)));
	}

	// delete action
	if ($action == 'delete') {
		// get id
		$id = isset($_GET['id']) ? $_GET['id'] : '';

		// contact does not exist
		if (!$db->existsContact($id)) {
			// give notice to client
			http_response_code(404);
			exit(json_encode(array(
				'status' => 404,
				'message' => 'delete failed: contact not found'
			)));
		}

		// delete it
		$db->deleteContact($id);

		// give notice to client
		exit(json_encode(array(
			'status' => 200,
			'message' => 'delete OK'
		)));
	}

	// sort action
	if ($action == 'sort') {
		// get contact ids
		$contactIds = isset($_GET['contact']) ? $_GET['contact'] : array();

		// we have passed in contacts
		if (sizeof($contactIds) > 0) {
			foreach ($contactIds as $i => $contactId) {
				$contact = $db->getContact($contactId);
				$contact->sortorder = ($i + 1);
				$db->updateContact($contact);
			}
		}

		// give notice to client
		exit(json_encode(array(
			'status' => 200,
			'message' => 'sorting OK'
		)));
	}

	// invalid action
	http_response_code(400);
	exit(json_encode(array(
		'status' => 400,
		'message' => 'invalid API call'
	)));

