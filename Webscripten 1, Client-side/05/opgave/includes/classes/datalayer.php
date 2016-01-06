<?php

	/**
	* Includes
	* ----------------------------------------------------------------
	*/

	// includes
	require_once  __DIR__ . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'functions.php';
	require_once  __DIR__ . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR .  'config.php';
	require_once  __DIR__ . DIRECTORY_SEPARATOR . 'contact.php';

	/**
	* DataLayer Class
	*
	* @author    Rogier van der Linde <rogier.vanderlinde@kahosl.be>
	*/

	class DataLayer {

		/**
		 * Database connection handler
		 */
		var $link;

		/**
		 * Class constructor.
		 */
		public function __construct() {
			$this->link = @mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME) or showError(mysqli_connect_error($this->link), 'connect');
		}

		/**
		 * Delete a contact
		 *
		 * @param	int 	$id The id of the contact to delete
		 * @return	void
		 */
		public function deleteContact($id) {
			// build query
			$query = sprintf('DELETE FROM contacts WHERE id = %d',
				(int) $id
			);

			// execute query
			@mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// check if contact to delete was found
			if (@mysqli_affected_rows($this->link) == 0) {
				 showError('contact with id ' . $id . 'not found', 'query');
			}

			// remove picture
			$pictureUrl = 'files/avatars/avatar_' . $id . '.jpg';
			@unlink($pictureUrl); // or showError('unable to remove picture ' . $pictureUrl, 'file');
		}

		/**
		 * Checks whether a contact exists or not
		 *
		 * @param	int 		$id Id of the contact
		 * @return	bool
		 */
		public function existsContact($id) {
			// build query
			$query = sprintf('SELECT * FROM contacts WHERE id = %d',
				(int) $id
			);

			// execute query
			$result = @mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// return result
			return mysqli_num_rows($result) == 1;
		}

		/**
		 * Get a contact by id
		 *
		 * @param	int 		$id Id of the contact
		 * @return	array
		 */
		public function getContact($id) {
			// build query
			$query = sprintf('SELECT * FROM contacts WHERE id = %d',
				(int) $id
			);

			// execute query
			$result = @mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// result found?
			if (!($record = @mysqli_fetch_array($result))) showError('contact with id ' . $id . ' not found', 'query');

			// return result
			return new Contact($record['id'], $record['name'], $record['email'], $record['role'], $record['comments'], $record['sortorder']);
		}

		/**
		 * Get all contacts
		 *
		 * @param	string[optional] 	$orderBy Field to sort contacts on
		 * @return	array
		 */
		public function getContacts($orderBy = 'sortorder') {
			// results array
			$contacts = array();

			// build query
			$query = sprintf('SELECT * FROM contacts ORDER BY %s',
				mysqli_real_escape_string($this->link, $orderBy)
			);

			// execute query
			$result = @mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// add results
			while ($record = mysqli_fetch_array($result)) {
				$contacts[] = new Contact($record['id'], $record['name'], $record['email'], $record['role'], $record['comments'], $record['sortorder']);
			}

			// return results
			return $contacts;
		}

		/**
		 * Insert a contact
		 *
		 * @param	Contact 	$contact The contact to insert
		 * @return	int 		the id of the contact inserted
		 */
		public function insertContact($contact) {
			// if not provided, find next order
			if (!$contact->sortorder || $contact->sortorder < 0) {
				$lastSortorder = $this->getMaxVal('contacts', 'sortorder');
				if (!$lastSortorder) $lastSortorder = 0;
				$contact->sortorder = $lastSortorder + 1;
			}

			// build query
			$query = sprintf('INSERT INTO contacts (name, email, role, comments, sortorder) VALUES ("%s", "%s", "%s", "%s", "%d")',
				mysqli_real_escape_string($this->link, $contact->name),
				mysqli_real_escape_string($this->link, $contact->email),
				mysqli_real_escape_string($this->link, $contact->role),
				mysqli_real_escape_string($this->link, $contact->comments),
				(int) $contact->sortorder
			);

			// execute query
			@mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// return id
			return mysqli_insert_id($this->link);
		}

		/**
		 * Update a contact
		 *
		 * @param	Contact 	$contact The contact to update
		 * @return	void
		 */
		public function updateContact($contact) {
			// build query
			$query = sprintf('UPDATE contacts SET name = "%s", email = "%s", role = "%s", comments = "%s", sortorder = "%d" WHERE id = %d',
				mysqli_real_escape_string($this->link, $contact->name),
				mysqli_real_escape_string($this->link, $contact->email),
				mysqli_real_escape_string($this->link, $contact->role),
				mysqli_real_escape_string($this->link, $contact->comments),
				(int) $contact->sortorder,
				(int) $contact->id
			);

			// execute query
			$result = @mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// check if contact to update was found
			// if (@mysqli_affected_rows($this->link) == 0) {
			if ($result === false) {
				 showError('contact with id ' . $contact->id . ' not found', 'query');
			}
		}

		/**
		 * Find the maximum value of a field; returns null if not found
		 *
		 * @param	string 	$table The table name
		 * @param	string 	$Field The field to look in
		 * @return	mixed
		 */
		public function getMaxVal($table, $field) {
			// build query
			$query = sprintf('SELECT MAX(%s) FROM %s',
				mysqli_real_escape_string($this->link, $field),
				mysqli_real_escape_string($this->link, $table)
			);

			// execute query
			$result = @mysqli_query($this->link, $query) or showError(mysqli_error($this->link), 'query');

			// result found?
			if (!($record = @mysqli_fetch_array($result))) return null;

			// return result
			return $record[0];
		}


	}

// EOF
