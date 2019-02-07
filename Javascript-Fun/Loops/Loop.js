/*
 * Loops
 * @Author Jason Bowerman
 * This program is just having a little bit of fun with the cos and sin functions
 * with a little bit of arrays.
 */

let _X,x,xx; 
let _Y,y,yy; 
let r,rr;
let speed1,speed2;
let trace;
let clear;
let points = [];
let maxPoints;
let tr = true;

function setup()
{
	createCanvas(400,400);
	//set max points
	maxPoints = 1000;
	//set center
	_X = width/2;
	_Y = height/2;
	//init rotations
	r = 0;
	rr = 0;
	//init sliders
	speed1 =  createSlider(0,1,0,0.001);
	speed2 =  createSlider(0,1,.059,0.001);
	speed2.position(10,40);
	speed1.position(10,10);

	//init trace checkbox
	trace = createCheckbox('Enable Tracing', true);
	trace.changed(enableDisable);
	trace.position(500,10);

	//init clear button
	clear = createButton('clear');
	clear.position(500,30);
	clear.mousePressed(clearPoints);
}
function draw()
{
	background(0);
	fill(255);
	strokeWeight(1);
	stroke(255);

	//first ball
	x = cos(r)*100+_X;
	y = sin(r)*100+_Y;
	ellipse(x,y,20);
	line(_X,_Y,x,y);

	//second ball
	xx = cos(rr)*50+x;
	yy = sin(rr)*50+y;
	ellipse(xx,yy,20);
	line(x,y,xx,yy);

	//tracing 
	if(tr)
		tracing();

	//increment rotations
	r += speed1.value();
	rr += speed2.value();
	
}
//function to enable or disable tracing
function enableDisable()
{
	if(this.checked())
		tr = true;
	else
		tr = false;
}
//function to trace where the balls are. It also removes elements if there start to be too many.
function tracing()
{

	points.push({xx,yy});
	for(let i = 0; i < points.length;i++)
	{
		ellipse(points[i].xx, points[i].yy,10);
	}
	if(points.length >= maxPoints )
		points.splice(0,1);
	
}
//function to clear the points array
function clearPoints()
{
	points = [];
}