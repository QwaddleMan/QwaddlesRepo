public class Block extends GameObject{
  
  private float w,h;
  private float r = 255,g = 255,bl = 255;
  private boolean exists = true;
  private boolean showCollider = false;
  private int id;
  
  //colliders
  private JRect [] b;
  
  Block(float x, float y, float w, float h, int id)
  {
    Pos = new JVector(x,y);
    Vel = new JVector(VecType.Zero);
    Acc = new JVector(VecType.Zero);
    this.w = w;
    this.h = h;
    this.id = id;
    
    if(this.id == 1)
    {
      this.b = new JRect[2];
      this.b[0] = new JRect(Pos.x, Pos.y, this.w, this.h/2,"top");
      this.b[1] = new JRect(Pos.x, Pos.y+this.h/2, this.w, this.h/2,"bottom");
     
    }
    else if(this.id == 2)
    {
      this.b = new JRect[1];
      this.b[0] =  new JRect(Pos.x, Pos.y, this.w, this.h,"top");
    }
    
    setBounds(this.b);
  }
  
  public void showCollider(boolean a)
  {
   showCollider = a; 
  }
  
  
  public void Exists(boolean a)
  {
    exists = a;
    JRect [] none = {};
    if(a == false)
      setBounds(none);
    else
      setBounds(b);
  }
  
  public boolean getShowCollider()
  {
    return showCollider;
  }
  
  public boolean getExists()
  {
    return exists;
  }
  
  public void setRandomColor()
  {
    r = random(255);
    g = random(255);
    bl = random(255);
  }
  public void update()
  {
    if(exists)
    {
      Pos.add(Vel);
      Vel.add(Acc);
      updateBounds();
    }
    
  }
  public void display()
  {
    if(exists)
    {
      fill(r,g,bl);
      noStroke();
      rect(Pos.x, Pos.y, w, h);
    }
    if(showCollider)
    {
      noFill();
      stroke(255,0,0);
      for(int i = 0; i < Bounds.length; i++)
      {
        rect(Bounds[i].x, Bounds[i].y, Bounds[i].w, Bounds[i].h);
      }
    }
  }
  
  public void updateBounds()
  {
    if(this.id == 1)
    {
      this.b[0] = new JRect(Pos.x, Pos.y, this.w, this.h/2,"top");
      this.b[1] = new JRect(Pos.x, Pos.y+this.h/2, this.w, this.h/2,"bottom");
     
    }
    else if(this.id == 2)
    {
      this.b[0] =  new JRect(Pos.x, Pos.y, this.w, this.h,"top");
    }
    
    setBounds(this.b);
  }
};
