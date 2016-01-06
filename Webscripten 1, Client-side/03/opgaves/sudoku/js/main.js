/**
 * Script for sudoku
 * @author  Haroen Viaene <hello@haroen.me>
 */

// encapsulating function
(function() {
    "use strict";

    // variable declaration for board, rows and all cells
    var board;
    var rows;
    var cells;

    // set a certain value to a cell.
    var setValue = function (cell) {
        var val = cell.textContent;

        // check if we got the value
        // console.log(val);

        // check if a number between (incl) 1 and 9
        if (!isNaN(val) && val < 10 && val > 0) {
            cell.innerHTML = val;
        } else {
            cell.innerHTML = "";
        }
    };

    var checkBoard = function() {
        var errors = 0, empty = 0;

        // what to do with an invalid input
        var invalid = function (cell) {
            if (cell.className !== "invalid") errors++;
            cell.className = "invalid";
        };

        // remove classes
        for (var i = 0; i < cells.length; i++) {
            cells[i].className = "";
        }

        // check if a double occurs in a group.
        // adds invalid class if it's double.
        var checkDouble = function(arr) {
            for(var i = 0; i < arr.length; i++) {
                if(arr[i].textContent == '') continue;
                for(var j = i+1; j < arr.length; j++) {
                    if(arr[i].textContent == arr[j].textContent) {
                        invalid(arr[i]);
                        invalid(arr[j]);
                    }
                }
            }
        };

        // look for the amount of empty cells
        for (var i = 0; i < cells.length; i++) {
            if (cells[i].innerHTML === "") {
                empty++;
            }
        };

        // check if no double values in rows
        for (var i = 0; i < rows.length; i++) {
            var rowCells = rows[i].getElementsByTagName("td");
            checkDouble(rowCells);
        };

        // check if no double values in columns
        for (var j = 0; j < rows.length; j++) {
            var colCells = new Array();
            for (var i = 0; i < rows.length; i++) {
                colCells.push(cells[9*i+j]);
            };
            checkDouble(colCells);
        };
        
        // check if no double values in block
        // todo: finish
        for (var i = 0; i < rows.length; i += 3) {
            blockCells = new Array();
            for (var j = 0; j < rows.length; j++ ) {
                // add to blockCells if in block i.
            };
            checkDouble(blockCells);
        };

        // adjust "to fill in" and "errors"
        document.getElementById("numEmptyCells").innerHTML = empty;
        document.getElementById("numErrors").innerHTML = errors;

        if (errors === 0 && empty == 0) {
            document.getElementById("alertDone").style.display = "inline-block";
        };
    };

    // things that happen when the page is loaded
    window.addEventListener("load", function() {
        board = document.getElementById("gameboard");
        rows = board.getElementsByTagName("tr");
        cells = board.getElementsByTagName("td");

        // check the board when loaded.
        checkBoard();

        board.addEventListener("keyup", function(ev){

            // set the value if it's correct 
            setValue(ev.target);

            // check the whole table
            checkBoard();

            // blur (get out of current cell)
            ev.target.blur();
        });      
    });
})();