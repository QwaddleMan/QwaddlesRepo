import java.util.Vector;
/*
@Author Jason 
@Date: 12/11/2018
@Description:
  1979 version of Asteroids
  
  
I aim to make this game as close to the original 1979 version of the game. 
using https://www.ign.com/faqs/2003/3-d-asteroids-general-faq-430472
as a reference to how the game should be made.
*/
Ship s;
Vector<Asteroid> astroidos;
String scoreText;
int score = 0;
public void setup()
{
  size(800,800,P2D);
  
  s = new Ship();
  astroidos = new Vector<Asteroid>();
  for(int i = 0; i < 5; i++)
  {
   astroidos.add(new Asteroid(30)); 
  }
}

public void draw()
{
  background(0);
  s.updateShip();
  s.Display();
  
  checkAstroidShipCollisions(s);
  displayScore();
  
  
  for(int i = 0; i < astroidos.size(); i++)
  {
   astroidos.get(i).updateAstroid(); 
   astroidos.get(i).Display(); 
  }
  
  checkAllAsteroids(s);
  
  if(astroidos.size() == 0)
  {
   addAstroids(5); 
  }
}

//reset
//resets the game back to original state
public void reset()
{
  if(s.getLives() > 1)
  {
     s.reposition();
     s.resetProjectiles();
     s.decrementLives();
  }
  else
  {
    s.reposition();
    s.resetProjectiles();
    score = 0;
    s.setLives(3);
    astroidos = new Vector<Asteroid>();
    for(int i = 0; i < 5; i++)
    {
     astroidos.add(new Asteroid(30)); 
    }
  }
  
  
}

//checkAstroidShipCollisions
//checks if the ship collides with any astroids and if it does destroy the ship
public void checkAstroidShipCollisions(Ship s)
{
  for(int i = 0; i < astroidos.size(); i++)
  {
   if(s.hitAstroid(astroidos.get(i)))
   {
    reset();
   }
  }
}

//displayScore
//draws the score to the screen 
public void displayScore()
{
  textSize(32);
  fill(255);
  scoreText = "Score: " + score + "  Lives: " + s.getLives(); 
  text(scoreText, width/2,50);
}

//addAstroids
//adds more astroids to the game
public void addAstroids(int amt)
{
  for(int i = 0; i < amt; i++)
  {
    astroidos.add(new Asteroid(30));
  }
}

//checkAllAsteroids
//checks if any astroids have been hit with a projectile and if so then destroy                           //this is honestly kinda gross
//that particular astroid and the projectile that collided with it
public void checkAllAsteroids(Ship sh)
{
  Vector<Projectile> project = sh.getProjectiles();
  Vector<Projectile> newProject = new Vector<Projectile>();
  Projectile temp;
  Vector<Asteroid> aTemp = new Vector<Asteroid>();
  
  
  for(int i = 0; i < project.size(); i++)
  {
    temp = project.get(i);
    for(int j = 0; j < astroidos.size(); j++)
    {
     if(temp.hitAstroid(astroidos.get(j)))
     {
      // print("HIT!\n");
       astroidos.get(j).setAlive(false);
       temp.setAlive(false);
       
       if(astroidos.get(j).getSize() == 30)//if you hit a large asteroid, make 2 medium asteroids, and add 20 points
       {
        aTemp.add(new Asteroid(20,new PVector(astroidos.get(j).getPos().x-20, astroidos.get(j).getPos().y - 20))); 
        aTemp.add(new Asteroid(20,new PVector(astroidos.get(j).getPos().x+20, astroidos.get(j).getPos().y + 20))); 
        score += 20;
       }
       
       if(astroidos.get(j).getSize() == 20)//if you hit a medium asteroid, make 2 small asteroids, and add 50 points
       {
        aTemp.add(new Asteroid(10,new PVector(astroidos.get(j).getPos().x-10, astroidos.get(j).getPos().y - 10))); 
        aTemp.add(new Asteroid(10,new PVector(astroidos.get(j).getPos().x+10, astroidos.get(j).getPos().y + 10))); 
        score += 50;
       }
       
      if(astroidos.get(j).getSize() == 10)//if you hit a small, add 100 points
       { 
        score += 100;
       }
       break;
     }
    }
  }
  
  
  for(int i = 0; i < astroidos.size();i++) //create the new asteroids vector
  {
   if(astroidos.get(i).getAlive())
     aTemp.add(astroidos.get(i));
  }
  
  for(int i = 0; i < project.size();i++) //create the new projectile vector
  {
   if(project.get(i).getAlive())
     newProject.add(project.get(i));
  }
  
  //set the new vectors
  sh.setProjectiles(newProject);
  astroidos = aTemp;
}


//input//
public void keyPressed()
{
 if(keyCode == LEFT)
 {
   s.shipRotation("counter-clockwise",1);
 }
 
 if(keyCode == RIGHT)
 {
  s.shipRotation("clockwise",1); 
 }
 
 if(keyCode == UP)
 {
  s.ThrustEngaged(true); 
 }
 
 if(key == ' ')
 {
 // print("FIRE"); 
  s.PewPew();
 }
  
}

public void keyReleased()
{
   if(keyCode == LEFT)
   {
     s.shipRotation("counter-clockwise",0);
   }
 
   if(keyCode == RIGHT)
   {
    s.shipRotation("clockwise",0); 
   }
   
   if(keyCode == UP)
   {
     s.ThrustEngaged(false); 
   }
   
}
