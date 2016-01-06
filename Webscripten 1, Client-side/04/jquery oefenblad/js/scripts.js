// 1. CSS

$('#btnCss1a').on('click',function() {
    $('#txtCss1').addClass('error');
});

$('#btnCss1b').on('click',function() {
    $('#txtCss1').removeClass('error');
});

$('#btnCss1c').on('click',function() {
    $('#txtCss1').css('color', 'blue');
});

$('#btnCss1d').on('click',function() {
    // $('#txtCss1').css({
    //     color: 'green',
    //     fontStyle: 'italic'
    // });
    $('#txtCss1').css('color', 'green').css('fontStyle', 'italic');
});

$('#btnCss1e').on('click',function() {
    console.log($('#txtCss1').width());
});

$('#btnCss1f').on('click',function() {
    console.log($('#txtCss1').width(600));
});

$('#btnCss1g').on('click',function() {
    $('#txtCss1').text('blablabla');
});


// 2. Selectors

$('#btnSel1a').on('click',function() {
    console.log($('#targetSel1 li').length);
});

$('#btnSel1b').on('click',function() {
   console.log($('#targetSel1 li').first().text());
});

$('#btnSel1c').on('click',function() {
    $('#targetSel1 li:nth-of-type(2n+1)').css('backgroundColor', 'lightGrey');
});

$('#btnSel1d').on('click',function() {
    $('#targetSel1 li a.removeMe').parent().remove();
});

$('#btnSel1e').on('click',function() {
    $('#targetSel1 li a').eq(2).css('fontWeight', 'bold');
});

$('#btnSel1f').on('click',function() {
    $('#targetSel1 li a:contains(link7)').css('fontStyle', 'italic');
});

$('#btnSel1g').on('click',function() {
});

// 3. Events

$('#btnEvents1a').on('mouseover',function() {
    console.log('ok');
});

$('#targetEvents1 a').first().on('click',function(e) {
    e.preventDefault();
    alert('google');
});

$('#btnEvents2a').on('click',function() {
    $('#targetEvents1 a').first().off();
});

$('#targetEvents2 a').on('click',function(e) {
    e.preventDefault();
    console.log($('#targetEvents2 a').index(this));
});

$('#tarEvents1').on('focus',function() {
    // $('#tarEvents1').text('').off();
    // not right
});

$('#tarEvents1').on('keydown',function(e) {
    if ((e.which == '115' || e.which == '83' ) && (e.ctrlKey || e.metaKey)) {
        e.preventDefault();
        e.stopPropagation();
        $('#msgEvents1').text($('#tarEvents1').text());
    }
});

// 4. Animaties

$('#btnAnim0').on('click',function(){
    $('#txtAnim0').toggle();
});

$('#btnAnim1').on('click',function(){
    $('#txtAnim1').fadeOut('slow');
});