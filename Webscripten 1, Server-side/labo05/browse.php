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
		$tpl = $twig->loadTemplate('browse.twig');

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

		$what = isset($_POST['what']) ? $_POST['what'] : ''; // The todo that was sent in via the form
		$priority = isset($_POST['priority']) ? $_POST['priority'] : 'low'; // The priority that was sent in via the form


	/**
	 * Handle action 'add' (user pressed add button)
	 * ----------------------------------------------------------------
	 */

		if (isset($_POST['moduleAction']) && ($_POST['moduleAction'] == 'add')) {


			// Check form: what not filled in
			if (trim($what) === '') {
				$formErrors[] = 'Please enter a name/description for your todo';
			}

			// Check form: priority not a correct value
			if (!in_array($priority, $priorities)) {
				$formErrors[] = 'Invalid priority selected';
			}

			// form is correct: insert values into database
			if (sizeof($formErrors) == 0) {

				// build & execute prepared statement
				$stmt = $db->prepare('INSERT INTO todolist (what, priority, added_on) VALUES (?, ?, ?)');
				$stmt->execute(array($what, $priority, (new DateTime())->format('Y-m-d H:i:s')));

				// the query succeeded, redirect to this very same page
				if ($db->lastInsertId() !== 0) {
					header('location: browse.php');
					exit();
				}

				// the query failed
				else {
					 $formErrors[] = 'Error while inserting the item. Please retry.';
				}

			}

		}


	/**
	 * No action to handle: show our page itself
	 * ----------------------------------------------------------------
	 */

		// Get all todo items from databases
		$stmt = $db->prepare('SELECT * FROM todolist ORDER BY priority, what DESC');
		$stmt->execute();

		$items = $stmt->fetchAll(PDO::FETCH_ASSOC);

		//twig
		$what = $item['what'];

		$url = $_SERVER['PHP_SELF'];

		echo $tpl->render(array(
			'what' => $what,
			'errors' => $formErrors,
			'url' => $url,
			'priorities' => $priorities,
			'priority' => $priority,
			'items' => $items
		));

?>