public class Asteroid{
  
  float size;
  PVector Pos,Vel;
  PShape astroid;
  boolean alive = true;
  
  //Constructor
  //creates the asteroid and sets the velocity to a random direction
  Asteroid(float size)
  {
     this.size = size;
     Pos = new PVector(random(width),random(height));
     
     while(Pos.x > width/2 + 20 && Pos.x < width/2 - 20 && Pos.y > height/2 + 20 && Pos.y < height/2 - 20)
     {
       Pos = new PVector(random(width),random(height));
     }
     
     Vel = new PVector(random(-2,2),random(-2,2));
     //print(Vel + "\n");
     while((Vel.x == 0) || (Vel.y == 0))
     {
       Vel = new PVector(random(-4,4),random(-4,4));
     }
     
     createAstroid();
  }
  
   //Constructor
  //creates the asteroid and sets the velocity to a random direction
  //this constructor takes a position and a size
  Asteroid(float size, PVector position)
  {
     this.size = size;
     Pos = position;
     Vel = new PVector(random(-2,2),random(-2,2));
     //print(Vel + "\n");
     while((Vel.x == 0) || (Vel.y == 0))
     {
       Vel = new PVector(random(-4,4),random(-4,4));
     }
     
     createAstroid();
  }
  
  //setAlive
  //sets the exsistance of this asteroid
  public void setAlive(boolean alive)
  {
   this.alive = alive; 
  }
  
  //getAlive
  //returns whether this asteroid is alive
  public boolean getAlive()
  {
    return alive;
  }
  
  //getPos
  //returns the position vector of this Asteroid
  public PVector getPos()
  {
    return Pos;
  }
  
  
  //createAstroid
  //this method creats the astroid shape
  public void createAstroid()
  {
    float randomVariation;
    PVector point;
    //THE ASTROID
    astroid = createShape();
    astroid.beginShape();
    astroid.stroke(255);
    astroid.strokeWeight(1);
    astroid.noFill();
    print("####\n");
    for(int i = 1; i < 360; i++)
    {
      if(i % 25 == 0)
      {
        print(i + "\n");
        randomVariation = random(-(.3*size),(.3*size));
        point = new PVector((size + randomVariation) * cos(radians(i)), (size + randomVariation) * sin(radians(i)));
        astroid.vertex(point.x,point.y);
      }
    }
    print("####\n");
    astroid.endShape(CLOSE);
    //astroid.translate(-size,-size);
  }
  
  //getSize
  //returns the size of asteroid
  public float getSize()
  {
   return size; 
  }
  
  //screenWrap
  //wraps the astroid around the screen
  public void screenWrap()
  {
    if(Pos.x < 0)
     Pos.x = width;
   if(Pos.x > width)
     Pos.x = 0;
   if(Pos.y < 0)
     Pos.y = height;
   if(Pos.y > height)
     Pos.y = 0;
  }
  
  //updateAstroid
  //updates the astroid position and existance
  public void updateAstroid()
  {
   Pos.add(Vel); 
   screenWrap();
  }
  
  //Display
  //draws the astroid to the screen
  public void Display()
  {
    if(alive)
      shape(astroid,Pos.x,Pos.y);
  }
};
