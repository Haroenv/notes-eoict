<?php

	/**
	 * Main Code
	 */
	error_reporting(E_ALL);
	ini_set('display_errors', 'on');

		// initial values
	$moduleAction = isset($_POST['moduleAction']) ? $_POST['moduleAction'] : '';
	$name = isset($_POST['name']) ? $_POST['name'] : '';
	$email = isset($_POST['email']) ? $_POST['email'] : '';
	$class = isset($_POST['class']) ? $_POST['class'] : '';
	$computer = isset($_POST['computer']) ? $_POST['computer'] : '';
	$type = isset($_POST['type']) ? $_POST['type'] : '';
	$description = isset($_POST['description']) ? $_POST['description'] : '';

		// form is sent: perform formchecking!
	if ($moduleAction == 'processName') {
	}

?>
<!DOCTYPE html>
<html>
<head>
	<title>Opgave 4</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">

		<fieldset>

			<h2>Testform</h2>

			<dl class="clearfix">

				<dt><label for="name">Name</label></dt>
				<dd class="text">
					<input type="text" name="name" value="<?php echo htmlentities($name)?>">
				</dd>

				<dt><label for="email">Email</label></dt>
				<dd class="text">
					<input type="text" name="email" value="<?php echo htmlentities($email)?>">
				</dd>

				<dt><label for="class">Class</label></dt>
				<dd class="text">
					<select name="class" id="class">
						<option value="lab1" <?php echo htmlentities($class) === 'lab1' ? 'selected' : ''; ?>>LAB ICT1</option>
						<option value="lab2" <?php echo htmlentities($class) === 'lab2' ? 'selected' : ''; ?>>LAB ICT2</option>
						<option value="lab3" <?php echo htmlentities($class) === 'lab3' ? 'selected' : ''; ?>>LAB ICT3</option>
						<option value="lab4" <?php echo htmlentities($class) === 'lab4' ? 'selected' : ''; ?>>LAB ICT4</option>
					</select>
				</dd>

				<dt><label for="computer">Computer number</label></dt>
				<dd class="text">
					<input type="text" name="computer"value="<?php echo htmlentities($computer)?>">
				</dd>

				<dt><label for="type">Type of problem</label></dt>
				<dd class="text">
					<input type="radio" name="type" ' <?php echo ((htmlentities($type) === 'hardware') ? 'checked' : '');?> ' value="hardware">hardware</input><br/>
					<input type="radio" name="type" ' <?php echo ((htmlentities($type) === 'software') ? 'checked' : '');?> ' value="software">software</input><br/>
				</dd>

				<dt><label for="description">Description</label></dt>
				<dd class="text">
					<textarea name="description" value="<?php echo htmlentities($description)?>"></textarea>
				</dd>

				<dt class="full clearfix" id="lastrow">
					<input type="hidden" name="moduleAction" value="processName" />
					<input type="submit" id="btnSubmit" name="btnSubmit" value="Send" />
				</dt>

			</dl>

		</fieldset>

	</form>
	<div id="debug">

<?php

/**
 * Helper Functions
 * ========================
 */

	/**
	 * Dumps a variable
	 * @param mixed $var
	 * @return
	 */
	function dump($var) {
		echo '<pre>';
		var_dump($var);
		echo '</pre>';
	}


/**
 * Main Program Code
 * ========================
 */

	// dump $_POST
dump($_POST);

?>

</div>
</body>
</html>