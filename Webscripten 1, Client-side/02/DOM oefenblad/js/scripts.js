/**
 * Clientside Scripting - Labo 02 - DOM
 * @author Rogier van der Linde <rogier.vanderlinde@odisee.be>
 *
 **/

window.addEventListener('load', function() {
	'use strict';

	// reeks 1
	document.getElementById('buttonA').addEventListener('click', function() {
		console.log(document.getElementById('textfield1').value);
	});
	document.getElementById('buttonB').addEventListener('click', function() {
		document.getElementById('textfield1').value = 'hallo';
	});
	document.getElementById('buttonE').addEventListener('click',function() {
		document.getElementById('button1').disabled = true;
	});
	document.getElementById('buttonF').addEventListener('click',function() {
		document.getElementById('button1').click();
	});
	document.getElementById('buttonG').addEventListener('click',function() {
		document.getElementById('checkbox1').checked = true;
	});
	document.getElementById('buttonH').addEventListener('click',function() {
		document.getElementById('checkbox2').checked = !document.getElementById('checkbox2').checked;
	});
	document.getElementById('buttonI').addEventListener('click',function() {
		document.getElementById('select1').selectedIndex = 2;
	});
	document.getElementById('buttonJ').addEventListener('click',function() {
		var sel = document.getElementById('select1');
		console.log(sel.options[sel.selectedIndex].innerHTML);
	});

	//reeks 2
	document.getElementById('buttonK').addEventListener('click',function() {
		document.getElementById('cursus1').alt = 'cursus rietdekken';
	});
	document.getElementById('buttonL').addEventListener('click',function() {
		document.getElementById('cursus1').src = 'img/cursus2.jpg';
		document.getElementById('cursus2').src = 'img/cursus1.jpg';
	});
	document.getElementById('buttonM').addEventListener('click',function() {
		document.getElementById('cursus2').width = 160;
	});

	// reeks 3
	document.getElementById('buttonN').addEventListener('click',function() {
		document.getElementById('place1').innerHTML = 'dit is plaats 1';
	});
	document.getElementById('buttonO').addEventListener('click',function() {
		document.getElementById('place2').style.color = 'blue';
	});
	document.getElementById('buttonP').addEventListener('click',function() {
		document.getElementById('place1').className = 'errorMsg';
	});
	document.getElementById('buttonQ').addEventListener('click',function() {
		document.getElementById('layer2').style.display = 'none';
	});
	document.getElementById('buttonR').addEventListener('click',function() {
		document.getElementById('layer1').style.zIndex = 3;
		document.getElementById('layer2').style.zIndex = 2;
		document.getElementById('layer3').style.zIndex = 1;
	});
	document.getElementById('buttonS').addEventListener('click',function() {
		document.getElementById('layer1').style.top = 0;
		document.getElementById('layer2').style.top = 0;
		document.getElementById('layer3').style.top = 0;
	});
	// reeks 4
	document.getElementById('buttonT').addEventListener('click',function() {
		//document.documentElement.style.background = 'grey';
		document.body.style.background = 'grey';
	});
	document.getElementById('buttonU').addEventListener('click',function() {
		location.href = 'https://google.com';
	});
	document.getElementById('buttonV').addEventListener('click',function() {
		document.title = 'testpagina';
	});
	document.getElementById('buttonW').addEventListener('click',function() {
		window.resizeTo(800,600);
	});
	document.getElementById('buttonX').addEventListener('click',function() {
		// niet af
		if(confirm('verander de achtergrondkleur naar blauw?')) {
			document.body.style.background = 'blue';
		}
	});

});