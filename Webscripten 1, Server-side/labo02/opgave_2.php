<?php

	/**
	 * Main Code
	 */

		// initial values
		$moduleAction = isset($_GET['moduleAction']) ? $_GET['moduleAction'] : '';
		$num1 = isset($_GET['num1']) ? (string) $_GET['num1'] : rand(0,1000);
		$num2 = isset($_GET['num2']) ? (string) $_GET['num2'] : rand(0,1000);

		// form is sent: perform formchecking!
		if ($moduleAction == 'processName') {

			$allOk = true;

			// num1 a number
			if (!is_numeric(trim($num1))) {
				$msgNum1 = 'Don\'t enter things that aren\'t numbers';
				$allOk = false;
			}

			// num2 a number
			if (!is_numeric(trim($num2))) {
				$msgNum2 = 'Don\'t enter things that aren\'t numbers';
				$allOk = false;
			}

			// num1 not empty
			if (trim($num1) == '') {
				$msgNum1 = 'Don\'t enter a an empty value';
				$allOk = false;
			}

			// num2 not empty
			if (trim($num2) == '') {
				$msgNum2 = 'Don\'t enter a an empty value';
				$allOk = false;
			}
		}

?>
<!DOCTYPE html>
<html>
<head>
	<title>Opgave 2</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="get">

		<fieldset>

			<h2>Testform</h2>

			<dl class="clearfix">

				<dt><label for="num1">Number 1</label></dt>
				<dd class="text">
					<input type="text" id="num1" name="num1" value="<?php echo htmlentities($num1); ?>" class="input-text" />
					<span class="message error"><?php echo $msgNum1; ?></span>
				</dd>

				<dt><label for="num2">Number 2</label></dt>
				<dd class="text">
					<input type="text" id="num2" name="num2" value="<?php echo htmlentities($num2); ?>" class="input-text" />
					<span class="message error"><?php echo $msgNum2; ?></span>
				</dd>

				<dt><label for="sum">Sum</label></dt>
				<dd class="text">
					<input type="text" id="sum" name="sum" value="<?php echo $allOk ? htmlentities($num1) + htmlentities($num2) : ''; ?>" class="input-text" disabled/>
					<span class="message error"><?php echo $msgSum; ?></span>
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