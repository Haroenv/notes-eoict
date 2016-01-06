// a

print('a. Hello World.');

// b

print('b. Enter two numbers');

var a = parseFloat(readline());
var b = parseFloat(readline());

print('average: ' + ((a+b)/2));

var average = 0;

for (var i = 0, l = arguments.length; i < l; i++) {
    average += parseFloat(arguments[i]);
}

average /= arguments.length;

// c

print('c. average: ' + average);

// d

var isEven = function(toCheck) {
    return toCheck % 2 === 0;
}

print('d. 2 is ' + (isEven(2) ? 'even' : 'not even') + ', 3 is ' + (isEven(3) ? 'even' : 'not even') + ', "cow" is ' + (isEven('cow') ? 'even' : 'not even'));

// e

/**
 * Counts the amount of times something occurs in an array
 * @param  {array} array      the array to check
 * @param  {}      contains   what to look for
 * @return {int}              the amount of times it occurs
 */
var containsCount = function(array,contains) {
    'use strict';
    var amount = 0;
    for (var i in array) {
        if (array[i] === contains) {
            amount++;
        };
    };
    return amount;
}

var arr = [1,3,5,'bla',true,false,123.5];

print('e. ' + containsCount(arr,true) + ', ' + containsCount(arr,'test') + ', ' + containsCount(arr,'false'));

// f

Array.prototype.containsCount = function(array,contains) {
    'use strict';
    var amount = 0;
    for (var i in array) {
        if (array[i] === contains) {
            amount++;
        };
    };
    return amount;
}

var arr = [1,3,5,'bla',true,false,123.5];

print('f. ' + true.containsCount() + ', ' + 'test'.containsCount() + ', ' + 'false'.containsCount);

