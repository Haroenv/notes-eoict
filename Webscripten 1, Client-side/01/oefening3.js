/**
 * Defines a rectangle of a certain width and height
 * @param {number} width   the width of that rectangle
 * @param {number} height  the height of that rectangle
 */
Rectangle = function(width, height) {
	this.width = width;
	this.height = height;

	/**
	 * calculates the circumference of the rectangle
	 * @return {number} the circumference
	 */
	this.getCircumference = function() {
		return 2*(this.width + this.height);
	}
}

/**
 * calculates the area of a rectangle
 * @return {number} the area of that rectangle
 */
Rectangle.prototype.getArea = function() {
	return this.width * this.height;
};

var r = new Rectangle(10,15);

print("circumference: " + r.getCircumference() + ", area: " + r.getArea());
