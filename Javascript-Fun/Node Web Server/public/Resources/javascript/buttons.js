
function hamburgerButton()
{
	let div = $('#wrapper');
	let ham = $('.hamburgerButton');
	
	if(div.css('top') == '0px')
		div.animate({top: '100px'},"slow");
	else
		div.animate({top: '0px'},"slow");
	
}