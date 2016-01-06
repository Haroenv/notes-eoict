;jQuery(function(){
    'use strict';

    /**
    * Function to show an item
    */
    var showItem = function($item) {
        // find big image
        var $photoBig = $('#photoBig');

        // change
        var $img = $item.find('img');
        $photoBig.attr('src', $img.attr('data-src-l'));
        $photoBig.attr('alt', $img.attr('alt'));

        // remove activeItem class from previous link and set to current; note: classList is only supported by IE10 and later
        var $activeItem = $('#thumbsmenu li.active');
        if ($activeItem.length) {
            $activeItem.removeClass('active');
        }
        $item.addClass('active');
    };

    /**
    * Function to show previous item
    */
    var showPreviousItem = function() {
        // find current active item
        var $activeItem = $('#thumbsmenu li.active');
        if (!$activeItem.length) {
            return;
        }

        // show previous
        var $previousItem = $activeItem.prev();
        if (!($previousItem.length)) {
            $previousItem = $('#thumbsmenu li:last-child');
        }
        showItem($previousItem);
    };

    /**
    * Function to show next item
    */
    var showNextItem = function() {
        // find current active item
        var $activeItem = $('#thumbsmenu li.active');
        if (!$activeItem.length) {
            return;
        }

        // show next
        var $nextItem = $activeItem.next();
        if (!$nextItem.length) {
            $nextItem = $('#thumbsmenu li:first');
        }
        showItem($nextItem);
    };

    // start scripts
    $(document).ready(function() {

        // add events to all items
        var $items = $('#thumbsmenu li');

        // todo: fix
        $items.on('click', function() {
            showItem($(this));
        });

        // if no item activeItem, activate first
        var $activeItem = $('#thumbsmenu li.active');
        if (!$activeItem) {
            $items.first().addClass('active');
        }

        // controls
        $('#lnkFirst').on('click', function(e) {
            showItem($items.first());
            e.preventDefault();
        });
        $('#lnkPrev').on('click', function(e) {
            showPreviousItem();
            e.preventDefault();
        });
        $('#lnkNext').on('click', function(e) {
            showNextItem();
            e.preventDefault();
        });
        $('#lnkLast').on('click', function(e) {
            showItem($items.last());
            e.preventDefault();
        });

        // keyboard
        $(document).on('keydown', function(e) {
            switch (e.which) {
                case 37: showPreviousItem(); e.preventDefault(); break;
                case 39: showNextItem(); e.preventDefault(); break;
            }
        });

        // play
        var timer;
        $('#btnPlay').on('click', function(e) {
            if (!$(this).playing() === true) {
                $(this).value('stop');
                $(this).playing(true);
                timer = setInterval(showNextItem, 1000);
            } else {
                $(this).value('start');
                $(this).playing(false);
                clearInterval(timer);
            }
        });

    });

});