public class Projectile{
  PVector Pos,Vel;//location and veloctiy of the projectile. velocity is different than speed;
  float speed;// how fast the projectile moves
  int deleter = 0;
  boolean alive = true;
  
  //constructor
  //sets location and velocity based on ship location and direction
  Projectile(Ship s, float speed)
  {
   this.speed = speed;
   Pos =  new PVector(8 * cos(s.getRotation()) + s.getPos().x,8 * sin(s.getRotation())+ s.getPos().y);
   Vel = new PVector();
   Vel.x = s.getVel().x +this.speed * cos(s.getRotation()+.25);
   Vel.y = s.getVel().y + this.speed * sin(s.getRotation()+.25);
  }
  
  public boolean getAlive(){return alive;} // returns alive
  public void setAlive(boolean alive){ this.alive = alive;} //sets alive
  
  //getPos
  //returns the projectile position vector
  public PVector getPos()
  {
    return Pos;
  }
  
  //getDeleter
  // returns the projectiles deleter
  public int getDeleter()
  {
   return deleter; 
  }
  
  //updateProjectile
  //updates the location of the projectile
  public void updateProjectile()
  {
   //checkForAstroidCollisions();
   Pos.add(Vel); 
   deleter += Vel.mag();//the deleter is basically the total distance the projectile has traveled
   screenWrap();        //I could not use the PVector dist() function to get distance because the projectile screen wraps so it could traverse forever and never move more than 400 px away from its original position
  }                     //this is a simple solution
  
  //screenWrap
  //wraps the projectile around the screen
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
  
  //hitAstroid
  //returns true if projectile hits the astroid a
  public boolean hitAstroid(Asteroid a)
  {
    boolean hit = false;
    float distance = Pos.dist(a.getPos());
    if(distance < a.getSize())
       return true; 
    //print(distance + "\n");
    return hit;
  }
  
  //Display
  //displays the projectile on the screen
  public void Display()
  {
    if(alive)
    {
      stroke(255);
      strokeWeight(3);
      point(Pos.x,Pos.y);
    }
  }
};
