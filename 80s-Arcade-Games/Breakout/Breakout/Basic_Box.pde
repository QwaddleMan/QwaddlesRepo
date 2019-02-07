//test class for a basic box...works pretty good

public class Basic_Box extends GameObject{
  
  float side = 1;
  int size;
  float r = 255,g = 255,b = 255;
  
  Basic_Box(float x, float y, int size)
  {
    Pos = new JVector(x,y);
    Vel = new JVector(VecType.Zero);
    Acc = new JVector(VecType.Zero);
    this.size = size;
    
    JRect [] b = {new JRect(Pos.x, Pos.y, side * size, side * size)};
    setBounds(b);
  }
  
  public void setRandomColor()
  {
    r = random(255);
    g = random(255);
    b = random(255);
  }
  public void update()
  {
    
    Pos.add(Vel);
    Vel.add(Acc);
    updateBounds();
    
  }
  public void display()
  {
    fill(r,g,b);
    noStroke();
    rect(Pos.x, Pos.y, side*size, side*size);
    noFill();
    stroke(255,0,0);
    rect(Bounds[0].x, Bounds[0].y, Bounds[0].w, Bounds[0].h);
  }
  
  public void updateBounds()
  {
    Bounds[0].setRect(Pos.x, Pos.y, side * size, side * size);
  }
};
