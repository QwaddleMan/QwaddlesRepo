let particles = [];
let p;

function setup()
{
  createCanvas(400,400);
}


function draw()
{
  background(0);

  //add 3 every frame
  for(let i = 0; i < 10; i++)
  {
    p = new Particle(random(width/2,width/2 + 40),height-30,10);
    particles.push(p);
  }

  for(let i = 0; i < particles.length; i++)
  {
    particles[i].update();
    particles[i].show();
  }
  for(let i = particles.length-1; i >= 0; i--)
  {
    if(particles[i].finished())
    {
      particles.splice(i,1);
    }
  }
}


class Particle{
  constructor(_x,_y,dia)
  {
    this.x = _x;
    this.y = _y;
    this.d = dia;
    this.vx = random(-1,1);
    this.vy = random(-3, -2);
    this.alpha = 255;
    this.red = random(210,250);
    this.green = 75;
    this.blue = 2;
    this.fade = 3
  }
  update()
  {
    this.x += this.vx;
    this.y += this.vy;
    this.alpha -= this.fade;
    this.red -=this.fade;
    this.green -= this.fade;
    this.blue -=this.fade;
  }
  finished()
  {
    return this.alpha <= 0;
  }
  show()
  {
    noStroke();
    if(this.alpha < random(95,110))
    {
      fill(this.alpha);
      //stroke(this.alpha);
    }
    else
    {
      fill(this.red,this.green,this.blue);
    //  stroke(this.red,this.green,this.blue);
    }
    //point(this.x, this.y);
    ellipse(this.x, this.y,this.d);
  }
}
