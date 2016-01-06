var MyUtils = MyUtils || {};

/**
 * Defines a billboard of a certain width and height.
 * Stored in a two-dimensional array 'raster'
 * @param {int}       numRows          the amount of rows, default 10
 * @param {int}       numCols          the amount of columns, default 10
 * @param {character} defaultCharacter the character to fill the grid with, default '.'
 */
MyUtils.Billboard = function(numRows, numCols, defaultCharacter) {
    // default values
    this.numRows = numRows || 10;
    this.numCols = numCols || 10;
    this.defaultCharacter = defaultCharacter || '.';

    // matrix for the billboard
    this.raster = [];
    // create function to initialize matrix
    this.init = function() {
        for (var i = 0; i < this.numRows; i++) {
            this.raster[i] = [];
            for (var j = 0; j < this.numCols; j++) {
                this.raster[i][j] = this.defaultCharacter;
            }
        }
    }

    this.addChar = function(x,y,char) {
        this.raster[x][y] = char;
    }

    this.draw = function(callback) {
        var matrix = "";
        for (var i = 0; i < this.raster.length ; i++) {
            for (var j = 0; j < this.raster[i].length; j++) {
                matrix += this.raster[i][j];
            }
            matrix += "\n";
        }
        print(matrix);
        callback();
    }

    // run initializer
    this.init();
}

var board = new MyUtils.Billboard();

board.draw();

board.addChar(3,5,"A");
board.addChar(3,6,"B");
board.addChar(3,7,"B");
board.addChar(3,8,"A");

var done = function() {
    print("all done");
}

board.draw(done);
