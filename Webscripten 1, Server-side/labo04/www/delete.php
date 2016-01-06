<?php

    // @TODO

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

	<script src="js/delete.js"></script>

</head>
<body>

	<div id="siteWrapper">

		<!-- header -->
		<header>
			<h1><a href="index.php">Todolist</a></h1>
		</header>

		<!-- content -->
		<section>

			<div class="box" id="boxCompleteTodo">

				<h2>Complete todo</h2>

<?php
	// @TODO Persist all values below
?>

				<div class="boxInner">
					<p>Are you sure you want to complete the todo <strong>...</strong>?</p>
					<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
						<fieldset class="columns">
							<label class="column column-12 cancel alignLeft"><a href="index.php" title="Cancel and go back">Cancel and go back</a></label>
							<label for="btnSubmit" class="column column-12 alignRight"><input type="submit" id="btnSubmit" name="btnSubmit" value="Complete" /></label>
							<input type="hidden" name="id" value="" />
							<input type="hidden" name="moduleAction" id="moduleAction" value="delete" />
						</fieldset>
					</form>
				</div>

			</div>

<?php
	// @TODO if any errors are set, show them inside <div class="box" id="boxError"><ul class="errors">...</ul></div>
?>
		</section>

		<!-- footer -->
		<footer>
			<p>&copy; 2014, <a href="http://www.ikdoeict.be/" title="IkDoeICT.be">IkDoeICT.be</a></p>
		</footer>

	</div>

</body>
</html>