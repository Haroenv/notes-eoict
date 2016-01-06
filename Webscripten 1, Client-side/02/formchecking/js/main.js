var checkForm = function() {
	'use strict';
	// clear error messages
	var errors = document.querySelectorAll('.message.error');
	for (var i = 0; i < errors.length; i++) {
		errors[i].innerHTML = '';
	};

	// check form, default true
	var valid = true;

	// check whether everything is filled in
	var inputs = document.querySelectorAll('input[type=text]');
	for (var i = 0; i < inputs.length; i++) {
		if (inputs[i].value === '') {
			errors[i].innerHTML = 'Dit is niet ingevuld';
			valid = false;
		}
	}

	// returns whether the form is true
	return valid;
}

window.addEventListener('load', function() {
	'use strict';
	document.getElementById('form1').addEventListener('submit', function(e) {
		e.preventDefault();
		if (checkForm()) {this.submit()};
	});
});