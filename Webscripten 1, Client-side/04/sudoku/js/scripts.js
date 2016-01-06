/*
 * Sudoku script
 * Self invoking function version
 *
 * @author Rogier van der Linde <rogier.vanderlinde@odisee.be>
 */

 // encapsulate script
jQuery(function(){
    'use strict';

    // shortcut to TABLE
    var $table;

    // list of all TR's
    var $rows;

    // 1D list of all TD's
    var $allcells;

    // sanatize cell value
    var setValue = function($cell) {
        var newVal = parseInt($cell.text(), 10);
        if (isNaN(newVal) || newVal < 1 || newVal > 9) newVal = '';
        $cell.text(newVal);
    };

    // check the board for errors and adjust numbers
    var checkBoard = function() {

        // remove all cell errors
        $allcells.removeClass('invalid');

        // check $rows
        $rows.each(function(i){

            // get row cells
            var $rowcells = $rows.eq(i).find('td');

            // check row
            $rowcells.each(function(j) {
                // get cell 1
                var $cell1 = $rowcells.eq(j);

                // ignore empty cells
                if ($cell1.text() === '') return;

                // test next cells in the same row
                $rowcells.each(function(k) {
                    // get cell 2
                    var $cell2 = $rowcells.eq(k);
                    // same value?
                    if ($cell1.text() == $cell2.text()) {
                        $cell1.addClass('invalid');
                        $cell2.addClass('invalid');
                    }
                });
            });
        });

        // check columns
        var $cols = $rows.eq(0).find('td');
        $cols.each(function(i){
            // get col cells
            var $colcells = $table.find('td:nth-of-type(' + (i + 1) + ')');

            // check column
            $colcells.each(function(j) {
                // get cell 1
                var $cell1 = $colcells.eq(j);

                // ignore empty cells
                if ($cell1.text() === '') return;

                // test next cells in the same row
                $colcells.each(function(k) {
                    // get cell 2
                    var $cell2 = $colcells.eq(k);

                    // same value?
                    if ($cell1.text() == $cell2.text()) {
                        $cell1.addClass('invalid');
                        $cell2.addClass('invalid');
                    }
                });
            });
        });

        // TODO: check cubes
        // ...


        // adjust number of empty cells
        var $numEmptyCells = 0;
        $allcells.each(function(i) {
            if ($allcells.eq(i).text() === '') $numEmptyCells++;
        });

        $('#numEmptyCells').text($numEmptyCells);

        // adjust number of errors
        var $numErrors = $table.find('td.invalid').length;
        $('#numErrors').text($numErrors);

        // done?
        if ($numEmptyCells === 0 && $numErrors === 0) {
            $allcells.each(function(i) {
                $allcells.eq(i).removeAttr('contenteditable');
            });
            $('#numErrors').text('Gefeliciteerd!'); //typo fix
        }
    };

    // bind all events
    $(document).ready(function() {
        // init vars
        $table = $('#gameboard');
        $rows = $table.find('tr');
        $allcells = $table.find('td');

        // listen to cell value changes
        $table.on('keyup', function(e) {
            // cell edited
            var $cell = $(e.target);
            setValue($cell);

            // blur unless delete or backspace was pressed
            if (e.keyCode != 8 && e.keyCode != 46) {
                $cell.blur();
            }

            // check the board
            checkBoard();

            // prevent any default action
            e.preventDefault();
            e.stopPropagation();
        });

    });

});