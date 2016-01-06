;jQuery(function(){
	'use strict';
	var $contacts = $('#contacts article');
	var $txtSearch = $('#txtSearch');

	// initial value for the number of people of a certain type
	var types = ["all",'family',"friends","colleagues","others"];
	var all = 0;
	var family = 0;
	var friends = 0;
	var colleagues = 0;
	var others = 0;

	// show search results realtime
	$txtSearch.on('keyup',function(){
		$contacts.each(function() {
			//todo: find why contains doesn't work on data
			console.log($txtSearch.val().toLowerCase());
			console.log($(this).data('searchstring').toLowerCase().contains('qsdf'));
			if (!$(this).data('searchstring').contains($txtSearch.val().toLowerCase())) {
				$(this).hide();
			} else {
				$(this).show();
			}
		});
	});

	// remove the tooltips if there's no comment set for a contact.
	$contacts.each(function() {
		$(this).find('.comments span').text();
		if ($(this).find('.comments span').text() === '') {
			$(this).find('.comments').remove();
		};
	});

	//show the number of friends, colleagues ...
	var updateCounters = function() {
		$('#filterLinks a').each(function() {
			var filter = $(this).data('filter');
			var num = 0;
			$contacts.each(function() {
				if ($(this).hasClass(filter)) num++;
			});
			$(this).next().text(num);
		});
	};

	// make the filter links filter on friends, family ...
	$('#filterLinks a').on('click', function(e){
		var filter = $(this).data('filter');
		$contacts.each(function() {
			if ($(this).hasClass(filter)) {
				$(this).show();
			} else {
				$(this).hide();
			}
		});
		$('#filterLinks a').removeClass('active');
		$(this).addClass('active');
		e.preventDefault();
	});

	//on document load
	$(document).ready(function() {
		updateCounters();
	});
});