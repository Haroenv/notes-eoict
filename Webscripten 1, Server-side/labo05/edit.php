<?php

	/**
	 * Includes
	 * ----------------------------------------------------------------
	 */


		// config & functions
		require_once 'includes/config.php';
		require_once 'includes/functions.php';
		require_once __DIR__ . '/includes/Twig/Autoloader.php';
		Twig_Autoloader::register();

		$loader = new Twig_Loader_Filesystem(__DIR__ . '/templates');
		$twig = new Twig_Environment($loader);
		$tpl = $twig->loadTemplate('edit.twig');

	/**
	 * Database Connection
	 * ----------------------------------------------------------------
	 */

		$db = getDatabase();


	/**
	 * Initial Values
	 * ----------------------------------------------------------------
	 */


		$priorities = array('low','normal','high'); // The possible priorities of a todo
		$formErrors = array(); // The encountered form errors

		$id = isset($_GET['id']) ? (int) $_GET['id'] : 0; // The passed in id of the todo

		$what = isset($_POST['what']) ? $_POST['what'] : ''; // The todo that was sent in via the form
		$priority = isset($_POST['priority']) ? $_POST['priority'] : 'low'; // The priority that was sent in via the form


	/**
	 * Handle action 'edit' (user pressed edit button)
	 * ----------------------------------------------------------------
	 */

		if (isset($_POST['moduleAction']) && ($_POST['moduleAction'] == 'edit')) {

			// get the id
			$id = isset($_POST['id']) ? (int) $_POST['id'] : 0;

			// check if item exists (use the id from the $_POST array!)
			$stmt = $db->prepare('SELECT COUNT(*) FROM todolist WHERE id = ?');
			$stmt->execute(array($id));
			$numItems = $stmt->fetchColumn();

			if ($numItems != 1) {
				header('location: browse.php');
				exit();
			}

			// Check form: what not filled in
			if (trim($what) == '') {
				$formErrors[] = 'Please enter a name/description for your todo';
			}

			// Check form: priority not a correct value
			if (!in_array($priority, $priorities)) {
				$formErrors[] = 'Invalid priority selected';
			}

			// form is correct: update values into database
			if (sizeof($formErrors) == 0) {

				// build and execute statement
				$stmt = $db->prepare('UPDATE todolist SET what = ?, priority = ?, added_on = ? WHERE id = ?');
				$stmt->execute(array($what, $priority, (new DateTime())->format('Y-m-d H:i:s'), $id));

				// the query succeeded, redirect to this very same page
				if ($stmt->rowCount() != 0) {
					header('location: browse.php');
					exit();
				}

				// the query failed
				else {
					 $formErrors[] = 'Error while updating the item. Please retry.';
				}

			}

		}


	/**
	 * No action to handle: show edit page
	 * ----------------------------------------------------------------
	 */

		// Check if the passed in id (in $_GET) exists as a todoitem
		$stmt = $db->prepare('SELECT * FROM todolist WHERE id = ?');
		$stmt->execute(array($id));

		if ($stmt->rowCount() != 1) {
			header('location: browse.php');
			exit();
		}

		// Get the item from the database
		$item = $stmt->fetch(PDO::FETCH_ASSOC);

		// If the form has not been sent, overwrite the $what and $priority parameters
		if (!isset($_POST['moduleAction'])) {
			$what = $item['what'];
			$priority = $item['priority'];
		}

		//twig
		$what = $item['what'];

		$url = $_SERVER['PHP_SELF'] . '?id=' . $id;

		echo $tpl->render(array(
			'what' => $what,
			'id' => $id,
			'errors' => $formErrors,
			'url' => $url,
			'priorities' => $priorities,
			'priority' => $priority
		));
?>