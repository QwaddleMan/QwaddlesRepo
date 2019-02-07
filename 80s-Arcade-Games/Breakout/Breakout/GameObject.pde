public abstract class GameObject{
  
  protected JVector Pos;
  protected JVector Vel;
  protected JVector Acc;
  protected JRect [] Bounds;
  
  public abstract void update(); //update object
  public abstract void display(); //display object
  public abstract void updateBounds(); //update bounds
  
  //reflectOffWindow
  //reflects the object off the sides of the window
  //returns what side it reflected off of
  public String reflectOffWindow()
  {
    //here we are assuming bounds[0] is the main colliding rectangle 
    //this could be problamatic later but for now its good
    if(Bounds[0].getX() < 0)
    {
      Vel.x *= -1;
      return "left";
    }
    if(Bounds[0].getX()+Bounds[0].getWidth() > width)
    {
      Vel.x *= -1;
      return "right";
    }
    if(Bounds[0].getY() < 0)
    {
      Vel.y *= -1;
      return "top";
    }
    if(Bounds[0].getY()+Bounds[0].getHeight() > height)
    {
      Vel.y *= -1;
      return "bottom";
    }
     
     
     return "none";
  }
  
  //Friction
  //slows the object down gradually
  public void Friction(float amt)
  {
    if(Vel.x != 0)
      Vel.x += (-1 * (Vel.x/abs(Vel.x))) * amt;
    if(Vel.y != 0)
      Vel.y += (-1 * (Vel.y/abs(Vel.y))) * amt;
      
    if(Vel.x < .1 && Vel.x > -.1)
      Vel.x = 0;
    if(Vel.y < .1 && Vel.y > -.1)
      Vel.y = 0;
  }
  
  //holdInFrame
  //doesnt let the object leave the frame
  public void holdInFrame()
  {
    if(Pos.x < 0 || Pos.x + Bounds[0].getWidth() > width)
    {
      Vel.x = 0;
      if(Pos.x < 0) Pos.x += 1; 
      else 
      Pos.x -= 1;
    }
    if(Pos.y < 0 || Pos.y + Bounds[0].getHeight() > height)
    {
      Vel.y = 0;
      if(Pos.y < 0) Pos.y += 1; 
      else 
      Pos.y -= 1;
    }
      
  }
  
  //Collides
  //returns true if this object collides with object obj
  public boolean Collides(GameObject obj)
  {
    JRect [] oRect = obj.getBounds();
    for(int i = 0; i < Bounds.length; i++)
    {
      for(int j = 0; j < oRect.length; j++)
      {
        if(Bounds[i].overlaps(oRect[j]))
          return true;
      }
    }
    
    return false;
  }
  
    //Collides
  //returns name of rect if this object collides with object obj and "noH" if no collision
  public String CollidesGetName(GameObject obj)
  {
    JRect [] oRect = obj.getBounds();
    for(int i = 0; i < Bounds.length; i++)
    {
      for(int j = 0; j < oRect.length; j++)
      {
        if(Bounds[i].overlaps(oRect[j]))
          return oRect[j].getRectName();
      }
    }
    
    return "noH";
  }
  
  //setBounds
  //sets the boundries of the game object
  public void setBounds(JRect [] bounds)
  {
   Bounds = bounds; 
  }
  
  //getBounds
  //get this objects boundries
  public JRect [] getBounds()
  {
    return Bounds;
  }
  
  //setPos
  //set the position
  public void setPos(float x, float y)
  {
   Pos.x = x;
   Pos.y = y;
  }
  
  //setVel
  //set the velocity
  public void setVel(float x, float y)
  {
   Vel.x = x;
   Vel.y = y;
  }
  
  //setAcc
  //set the acceleration
  public void setAcc(float x, float y)
  {
   Acc.x = x;
   Acc.y = y;
  }
  
  //getPos
  //return the position vector
  public JVector getPos()
  {
    return Pos;
  }
  
  //getVel
  //return the Velocity vector
  public JVector getVel()
  {
    return Vel;
  }
  
  //getAcc
  //return tha acceleration vector
  public JVector getAcc()
  {
    return Acc;
  }
  
  //addForce
  //add a force to the object
  public void addForce(JVector vec)
  {
    Vel.add(vec);
  }
  
  //setGravity
  //set the gravity. let it fall
  public void setGravity(float Gravity)
  {
   Acc.y = Gravity; 
  }
  
  
  
};
