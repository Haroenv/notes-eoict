<?php

	/**
	 * Main Code
	 */
    // error_reporting(E_ALL);
    // ini_set('display_errors', 'on');

		// initial values
		$moduleAction = isset($_POST['moduleAction']) ? $_POST['moduleAction'] : '';
		$memory = isset($_POST['memory']) ? $_POST['memory'] : '';
		$prices = array(
		    '4GB' => '€10',
		    '8GB' => '€3',
		    '16GB' => '$420'
		);
		$msgPrice = '';

		// form is sent: perform formchecking!
		if ($moduleAction == 'processName') {
			if (isset($memory)) {
				$msgPrice = 'De prijs is ' . $prices[$memory];
			}
		}

?>
<!DOCTYPE html>
<html>
<head>
	<title>Opgave 3</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">

		<fieldset>

			<h2>Testform</h2>

			<dl class="clearfix">

				<dt><label for="num1">Memory modules</label></dt>
				<dd class="text">
					<?php
					 foreach ($prices as $type => $price) {
					 	echo '<input type="radio" name="memory" ' . (($memory === $type) ? 'checked' : '') . ' value="' . $type  .'">' . $type . ' at ' . $price . '</input><br/>' . PHP_EOL;
					 }
					 ?>
				</dd>
				<span class="text"><?php echo $msgPrice ?>.</span>

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