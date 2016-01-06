<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<title>Contacten</title>
	<link rel="stylesheet" href="css/styles.css" />
	<link rel="stylesheet" href="css/forms.css" />
	<link rel="stylesheet" href="css/tooltips.css" />
	<link rel="stylsheet" href="http://code.jquery.com/ui/1.9.2/themes/base/jquery-ui.css" />
</head>
<body>
	<header>
		<h2>Contacten overzicht</h2>
	</header>
	<section id="filters">
		<form action="#">
			<dl>
				<dt><label for="txtSearch">Zoek op tekst: </label></dt>
				<dd><input type="text" id="txtSearch" name="txtSearch" /></dd>
				<dt><label>Toon: </label></dt>
				<dd id="filterLinks">
					<a href="#" id="lnkAll" class="active" data-filter="contact">iedereen</a> (<span id="numAll">0</span>) &mdash; 
					<a href="#" id="lnkFamily" data-filter="family">familie</a> (<span id="numFamily">0</span>) &mdash; 
					<a href="#" id="lnkFriends" data-filter="friend">vrienden</a> (<span id="numFriends">0</span>) &mdash; 
					<a href="#" id="lnkColleagues" data-filter="colleague">collega's</a> (<span id="numColleagues">0</span>) &mdash; 
					<a href="#" id="lnkOther" data-filter="other">andere</a> (<span id="numOther">0</span>)
				</dd>
			</dl>
		</form>
	</section>
	<div id="content" class="clearfix">
		<div class="add">
			+ <a href="insert.php">nieuw contact</a>...
		</div>

		<div id="contacts">
{iteration:iContacts}

		<article class="contact {$role|htmlentities} clearfix" id="contact_{$id}" data-id="{$id}" data-searchstring="{$searchstring|lowercase|htmlentities}">
			<h1>{$name}</h1>
			<a href="#"><img src="files/avatars/avatar_{$id}.jpg" alt="{$name|htmlentities}" class="thumb" /></a>
			<ul class="menu">
				<li>&gt; <a href="#" class="edit">bewerken</a>...</li>
				<li>&gt; <a href="#" class="delete">verwijderen</a>...</li>
			</ul>
			<p class="toolbar">
				<a href="#" class="comments tooltip"><img src="images/icons/info.gif" alt="icon comments" /><span>{$comments|htmlentities}</span></a>
				<a href="mailto:{$email|htmlentities}" title="email versturen" class="lnkmail"><img src="images/icons/mail.png" alt="icon mail" /></a>
			</p>
		</article>
{/iteration:iContacts}
		</div>
	</div>
	<footer>
		<p>Clientside Webscripting 1, 2013</p>
	</footer>

	<script src="js/jquery.min.js"></script>
	<script src="http://code.jquery.com/ui/1.9.2/jquery-ui.js"></script>
	<script src="js/scripts.js"></script>
</body>
</html>
