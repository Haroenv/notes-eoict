<?php

	/**
	 * Main Code
	 */

		// initial values
		$moduleAction = isset($_GET['moduleAction']) ? $_GET['moduleAction'] : '';
		$name = isset($_GET['name']) ? (string) $_GET['name'] : '';
		$msgName = '*';

		// form is sent: perform formchecking!
		if ($moduleAction == 'processName') {

			$allOk = true;

			// name not empty
			if (trim($name) == '') {
				$msgName = 'Please enter your name';
				$allOk = false;
			}

		}

?>
<!DOCTYPE html>
<html>
<head>
	<title>Opgave 1</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="get">

		<fieldset>

			<h2>Testform</h2>

			<dl class="clearfix">

				<dt><label for="name">Name</label></dt>
				<dd class="text">
					<input type="text" id="name" name="name" value="<?php echo htmlentities($name); ?>" class="input-text" />
					<span class="message error"><?php echo $msgName; ?></span>
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

		// dump $_GET
		dump($_GET);

?>

	</div>
</body>
</html>