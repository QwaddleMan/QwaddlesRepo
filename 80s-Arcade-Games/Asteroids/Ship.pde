import java.util.Vector;

public class Ship{
  PVector Pos, Vel, Acc;
  Vector<Projectile> projectiles; 
  float turnSpeed = .1;
  float slowdownSpeed = .08,thrusterPower = .5;
  float rotation = -1.8;
  boolean left = false, right = false, thrusters = false;
  PShape ship;
  int lives = 3;
  
  //Constructor
  //sets all the location variables and creates the ship shape
  Ship()
  {
    Acc = new PVector(0,0);
    Vel = new PVector(0,0);
    Pos = new PVector(width/2, height/2);
    projectiles = new Vector<Projectile>();
    
    //THE SHIP
    ship = createShape();
    ship.beginShape();
    ship.stroke(255);
    ship.strokeWeight(1);
    ship.noFill();
    ship.vertex(15,0);
    ship.vertex(0,30);
    ship.vertex(3.75f,24);
    ship.vertex(27.75f,24);
    ship.vertex(30,30);
    ship.vertex(15,0);
    ship.endShape();
    ship.translate(-15,-13);
    ship.rotate(0);
    
  }
  
  public void setProjectiles(Vector<Projectile> p){ projectiles = p;} //sets the projectile vector to a new set of projectiles
  public int getLives(){return lives;} //returns the amount of lives this ship has
  public void setLives(int l){lives = l;}//sets the number of lives this ship has
  public void decrementLives(){lives -= 1;}//decrements the number of lives this ship has by one
  
  
  //getPojectiles
  //returns the vector of projectiles for this ship
  public Vector<Projectile> getProjectiles()
  {
   return projectiles;
  }
  
  //getPos
  //returns the ships pos vector
  public PVector getPos()
  {
   return Pos;
  }
  
  //getVel
  //returns the velocity vector of this ship
  public PVector getVel()
  {
   return Vel; 
  }
  
  //resetProjectiles
  //resets the projectiles vector to have no projectiles
  public void resetProjectiles()
  {
   projectiles = new Vector<Projectile>(); 
  }
  
  //reposition
  //this method repostitions the ship in the center of the screen
  //and resets it rotation back to zero
  public void reposition()
  {
    Pos = new PVector(width/2,height/2);
    Vel = new PVector(0,0);
    ship.rotate(0);
  }
  
  public boolean hitAstroid(Asteroid a)
  {
    boolean hit = false;
    float dist = Pos.dist(a.getPos());
    
    if(dist < a.getSize() + 15)
      return true;
    
    return hit;
  }
  
   //getRotation
  //returns the ships rotation
  public float getRotation()
  {
   return rotation;
  }
  
  
  //PewPew
  //shoots a projectile
  public void PewPew()
  {
    //if(projectiles.size() < 4)
      projectiles.add(new Projectile(this, 4));
  }
  
  //updateAllProjectils
  //updates and displays all the projectiles in the projectiles vector
  public void updateAllProjectiles()
  {
    for(int i = 0; i < projectiles.size(); i++)
    {
     projectiles.get(i).updateProjectile();
     projectiles.get(i).Display();
     //print(projectiles.get(i).getDeleter() + "\n");
    }
    
   
    if(projectiles.size() > 0 && projectiles.get(0).getDeleter() > 500)
       projectiles.remove(0);
  }
  
  //screenWrap
  //if ship goes off the side of the screen then 
  //make it appear on the other side of the screen  
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
  
  //ThrustEngaged
  //engage or disengage the thrusters
  public void ThrustEngaged(boolean code)
  {
    thrusters = code;
  }
  
  //Thrust
  //adds the thrust to the velocity
  public void Thrust()
  {
     Acc.x = thrusterPower * cos(rotation);
     Acc.y = thrusterPower * sin(rotation);
     
      if(thrusters && Vel.mag() < 10)//if thrusters are engaged and the speed is less than 10
      {
        Vel.add(Acc);//add acceleration to velocity
      }
  }
  
  //killThrust
  //returns the acceleration slowly back to zero
  public void killThrust()
  {
    //slow down always
   if(Vel.x > 0)
     Vel.x -= slowdownSpeed;
   if(Vel.y > 0)
     Vel.y -= slowdownSpeed;
   if(Vel.x < 0)
     Vel.x += slowdownSpeed;
   if(Vel.y < 0)
     Vel.y += slowdownSpeed;
  }
  
  //updateShip
  //updates the ship ran once per frame
  public void updateShip()
  {
    
    //bullets
    updateAllProjectiles();
    //thrusters
     Thrust();
    //wrap ship around screen
    screenWrap();
    //fix thrust
    killThrust();
    //rotation
      if(right)
      {
       // print(rotation + "\n");
        rotation += turnSpeed;
        ship.rotate(turnSpeed);
      }
      if(left)
      {
        //print(rotation);
        rotation -= turnSpeed;
       ship.rotate(-turnSpeed);
      }
      
      
    //movement
    Pos.add(Vel);
  }
  
  //controls
  //the controls that move the ship around
  public void shipRotation(String dir, int code)
  {
    
    if(dir == "clockwise" && code == 1)
    {
      right = true;
      left = false;
    }
    else if(dir == "counter-clockwise" && code == 1)
    {
      left = true;
      right = false;
    }
    if(dir == "clockwise" && code == 0)
    {
      right = false;
    }
    else if(dir == "counter-clockwise" && code == 0)
    {
      left = false;
    }
  }
  
  //Draw the ship to the screen
  public void Display()
  {
    shape(ship,Pos.x,Pos.y);
  }
};
