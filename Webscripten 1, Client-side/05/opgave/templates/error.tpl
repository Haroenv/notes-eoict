<!DOCTYPE html>
<html>
<head>
	<title>Contacten</title>
	<link rel="stylesheet" href="css/styles.css" />
	<link rel="stylesheet" href="css/forms.css" />
</head>
<body>
	<header>
		<h2>Contacten foutpagina</h2>
	</header>
	<section id="filters">
		<form action="#">
			<dl>
				<dt><label for="txtSearch">Zoek op tekst: </label></dt>
				<dd><input type="text" id="txtSearch" name="txtSearch" /></dd>
				<dt><label>Toon: </label></dt>
				<dd>
					<a href="#" id="lnkAll" class="active">iedereen</a> (<span id="numAll">0</span>) &mdash; 
					<a href="#" id="lnkFamily">familie</a> (<span id="numFamily">0</span>) &mdash; 
					<a href="#" id="lnkFriends">vrienden</a> (<span id="numFriends">0</span>) &mdash; 
					<a href="#" id="lnkColleagues">collega's</a> (<span id="numColleagues">0</span>) &mdash; 
					<a href="#" id="lnkOther">andere</a> (<span id="numOther">0</span>)
				</dd>
			</dl>
		</form>
	</section>
	<div id="content" class="clearfix">
		<p>Er is ergens een onverwachte fout opgetreden, waarvoor onze excuses. </p>
	</div>
	<footer>
		<p>Clientside Webscripting 1, 2013</p>
	</footer>
</body>
</html>
