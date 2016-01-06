/**
 * Checks if two variables have the same key somewhere
 * @param  {Object} first  the first to check
 * @param  {Object} second the second to check
 * @return {boolean}       true if they share a key
 */
var haveSameKey = function(first, second) {
	for (var i in first) {
		for (var j in second) {
			if (i === j) {
				return true;
			};
		};
	};
	return false;
}


/**
 * Checks if two variables have the same value somewhere
 * @param  {Object} first  the first to check
 * @param  {Object} second the second to check
 * @return {boolean}       true if they share a value
 */
var haveSameValue = function(first, second) {
	for (var i in first) {
		for (var j in second) {
			if (first[i] === second[j]) {
				return true;
			};
		};
	};
	return false;
}

var green = {
	color: 'green',
	started: false,
	cylinders: 5
};

var red = {
	color: 'red',
	started: false,
	cylinders: 3
};

var philips = {
	screen: 'Philips TV',
	color: false,
	channels: 5
};

var loewe = {
	screen: 'Loewe',
	color: true,
	channels: 20
};

print(haveSameKey(loewe,philips));
print(haveSameValue(red,philips));
