//Jason Bowerman
/*
  This code will play with the gravity formula.
  Fg = (G*m1*m2)/r^2
*/
let G = 6.67e-11; //G is 6.67X10^-11
let p1;
let p2;
let p3;
function setup()
{
  createCanvas(500,500);
  angleMode(RADIANS);

  p1 = new Planet(createVector(200,200,0),200000); // arguments are position and mass
  p2 = new Planet(createVector(300,300,0),30000);
  p3 = new Planet(createVector(250,250,0),500000);
  p1.vel.y = .25;
  p2.vel.y = -.25;//give p1 and p2 a starting velocity
}
function draw()
{
  background(0);
  p1.grav(p2);
  p2.grav(p1); //apply gravity
  p1.grav(p3); // note that p3 is fixed. no gravity is acting on it but p1 and p2 are effected by its existance.
  p2.grav(p3);

  p3.update();
  p1.update();//update planets
  p2.update();


  p1.show();
  p2.show();
  p3.show();//show the planets
}
//planet class
class Planet{
  constructor(pos, m)
  {

    this.pos = pos;
    this.vel = createVector(0,0,0);
    this.acc = createVector(0,0,0);
    this.mass = m;
    this.ab = 0;
    this.dist;
    this.fg = 0;
    this.angle;
    this.dx;
    this.dy;
    this.norm = createVector(100,0);
  }
  update()
  {
    this.pos.add(this.vel);
    this.vel.add(this.acc);
  }

//method to do gravity and angle calculations
  grav(other)
  {
      //I might work on this some more. It took me a little while to get the angles right.
      this.ab = p5.Vector.sub(other.pos,this.pos);
      this.dist = this.pos.dist(other.pos);
      if(this.ab.y < 0)
      {
        this.angle = TWO_PI - this.norm.angleBetween(this.ab);
      }
      else
      {
        this.angle = this.norm.angleBetween(this.ab);
      }

      this.fg = (G*this.mass*other.mass)/this.dist;

      this.acc.x = this.fg*cos(this.angle);
      this.acc.y = this.fg*sin(this.angle);


  }
  show()
  {

    stroke(255);
    fill(255);
    ellipse(this.pos.x,this.pos.y,20);

  }
}
