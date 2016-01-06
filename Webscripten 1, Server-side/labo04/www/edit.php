<?php

	/**
	 * Includes
	 * ----------------------------------------------------------------
	 */


		// config & functions
		require_once 'includes/config.php';
		require_once 'includes/functions.php';


	/**
	 * Database Connection
	 * ----------------------------------------------------------------
	 */

		// @TODO
		try {
			$db = new PDO('mysql:host=' . DB_HOST .';dbname=' . DB_NAME . ';charset=utf8mb4', DB_USER, DB_PASS);
			$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		} catch (Exception $aight) {
			showDbError($aight->getMessage(),"database error");
		}


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
		var_dump($_POST);

			// check if item exists (use the id from the $_POST array!)
			if ($id == 0) {
				// @TODO (if error, redirect to browse.php)
				header('location: error.php?msg=this%20id%20is%20fake');
			}
			if ($what == '') {
				array_push($formErrors, 'A todo needs a title xxx groetjes Bram');
			} else {
				//todo
				$stmt = $db->prepare('INSERT INTO todolist (what,priority) VALUES (?,?)');
				$stmt->execute(array(htmlentities($what),$priority));
				header('location: browse.php');
			}

			// check parameters

				// @TODO (if an error was encountered, add it to the $formErrors array)

			// if no errors: updates values in the database

				// @TODO

			// if query succeeded: redirect to browse.php

				// @TODO


		}


	/**
	 * No action to handle: show edit page
	 * ----------------------------------------------------------------
	 */

		// @TODO Check if the passed in id (in $_GET) exists as a todoitem (if it fails, redirect to browse.php)
		if (true) {

		} else {
			header('location: browse.php');
		}
		// @TODO Get the item from the database

		// @TODO If the form has not been sent, overwrite the $what and $priority parameters



?><!DOCTYPE html>
<!--[if lt IE 7 ]><html class="oldie ie6" lang="en"><![endif]-->
<!--[if IE 7 ]><html class="oldie ie7" lang="en"><![endif]-->
<!--[if IE 8 ]><html class="oldie ie8" lang="en"><![endif]-->
<!--[if IE 9 ]><html class="ie9" lang="en"><![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--><html lang="en"><!--<![endif]-->
<head>

	<title>Todolist</title>

	<meta charset="UTF-8" />
	<meta name="viewport" content="width=520" />
	<meta http-equiv="cleartype" content="on" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />

	<!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->

	<link rel="stylesheet" media="screen" href="css/reset.css" />
	<link rel="stylesheet" media="screen" href="css/screen.css" />

	<script src="js/edit.js"></script>

</head>
<body>

	<div id="siteWrapper">

		<!-- header -->
		<header>
			<h1><a href="index.php">Todolist</a></h1>
		</header>

		<!-- content -->
		<section>

			<div class="box" id="boxAddTodo">

				<h2>Edit existing todo</h2>

<?php
	// @TODO Persist all values below
?>

				<div class="boxInner">
					<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
						<fieldset>
							<dl class="clearfix columns">
								<dd class="column column-46"><input type="text" name="what" id="what" value="<?php $what ?>" /></dd>
								<dd class="column column-16" id="col-priority">
									<select name="priority" id="priority">
<?php
	// @TODO loop priorities and show them as options in the select. Be sure to persist the value
	foreach ($priorities as $thisPriority) {
		echo '<option value="' . $thisPriority . '" ' . ($thisPriority == $priority ? 'selected' : '') .'>' . $thisPriority . '</option>';
	}
?>
									</select>
								</dd>
								<dd class="column column-16" id="col-submit">
									<label for="btnSubmit"><input type="submit" id="btnSubmit" name="btnSubmit" value="Edit" /></label>
									<input type="hidden" name="id" value="" />
									<input type="hidden" name="moduleAction" id="moduleAction" value="edit" />
								</dd>
							</dl>
						</fieldset>
					</form>
					<p class="cancel">or <a href="index.php" title="Cancel and go back">Cancel and go back</a></p>
				</div>

			</div>

<?php
	// @TODO if any errors are set, show them inside <div class="box" id="boxError"><ul class="errors">...</ul></div>
	if (count($formErrors) > 0) {
		echo '<div class="box" id="boxError"><ul class="errors">';
		foreach ($formErrors as $error) {
			echo '<li>' . $error . '</li>';
		}
		echo '</ul></div>';
	}
?>
		</section>

		<!-- footer -->
		<footer>
			<p>&copy; 2014, <a href="http://www.ikdoeict.be/" title="IkDoeICT.be">IkDoeICT.be</a></p>
		</footer>

	</div>

</body>
</html>