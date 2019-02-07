public class Ball extends GameObject{
  
  float radius;
  
  Ball(float x, float y, float radius)
  {
    Pos = new JVector(x,y);
    Vel = new JVector(VecType.Zero);
    Acc = new JVector(VecType.Zero);
    this.radius = radius;
    
    JRect [] b = {new JRect(Pos.x - radius, Pos.y-radius, radius*2, radius*2)};
    
    setBounds(b);
  }
  
  public void update()
  {
    
    //keep from blowing speed out of proportion when
    //the ball hits 2 blocks at once
    if(Vel.x > 10 || Vel.x < -10)
      Vel.x = (Vel.x/abs(Vel.x)) * 10;
    if(Vel.y > 10 || Vel.y < -10)
      Vel.y = (Vel.y/abs(Vel.y)) * 10;
      
     
    
    Pos.add(Vel);
    Vel.add(Acc);
    updateBounds();
  }
  public void display()
  {
    fill(255);
    noStroke();
    ellipse(Pos.x, Pos.y,radius*2,radius*2);
    //noFill();
    //stroke(255,0,0);
    //rect(Bounds[0].getX(), Bounds[0].getY(), Bounds[0].getWidth(), Bounds[0].getHeight());
    
  }
  public void updateBounds()
  {
    Bounds[0].setRect(Pos.x - radius, Pos.y - radius, radius*2, radius*2);
  }
  
};
