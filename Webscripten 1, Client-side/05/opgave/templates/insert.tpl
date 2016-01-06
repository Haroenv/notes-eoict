<!DOCTYPE html>
<html>
<head>
	<title>Contacten</title>
	<link rel="stylesheet" href="css/styles.css" />
	<link rel="stylesheet" href="css/forms.css" />
</head>
<body>
	<header>
		<h2>Contact toevoegen</h2>
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
		<form action="#" enctype="multipart/form-data" method="post">
			<dl>
				<dt><label for="name">Naam: </label></dt>
				<dd><input type="text" size="40" name="name" id="name" /></dd>
				<dt><label for="name">Email: </label></dt>
				<dd><input type="text" size="40" name="email" id="email" /></dd>
				<dt><label for="picture">Foto (optioneel): </label></dt>
				<dd><input type="file" size="40" name="picture" id="picture" /></dd>
				<dt><label>Aard van het contact:</label></dt>
				<dd>
					<label><input type="radio" name="role" id="role_family" value="family" /> familie</label>
					<label><input type="radio" name="role" id="role_friend" value="friend" /> vriend</label>
					<label><input type="radio" name="role" id="role_colleague" value="colleague" /> collega</label>
					<label><input type="radio" name="role" id="role_other" value="other" checked="checked" /> andere</label>
				</dd>
				<dt><label for="comments">Opmerkingen: </label></dt>
				<dd><textarea rows="5" cols="40" name="comments" id="comments"></textarea></dd>
				<dt class="full clearfix" id="lastrow">
					<input type="submit" id="btnOk" name="btnOk" value="Toevoegen" />
					<input type="submit" id="btnCancel" name="btnCancel" value="Annuleren" />
					<input type="hidden" id="id" name="id" value="{$id}" />
				 </dt>
			</dl>
		</form>
	</div>
	<footer>
		<p>Clientside Webscripting 1, 2013</p>
	</footer>
</body>
</html>
