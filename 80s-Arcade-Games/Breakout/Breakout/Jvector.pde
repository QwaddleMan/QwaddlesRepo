
public enum VecType{ //the vector types
    Zero,
    One
  };
  
  
public class JVector{
  
  public float x,y;//components
  
  //constructor for setting zero vector or unit vector
  JVector(VecType t)
  {
    if(t == VecType.Zero)
    {
      x = 0;
      y = 0;
    }
    
    if(t == VecType.One)
    {
     x = 1;
     y = 1;
    }
  }
  
  //constructor
  JVector(float _x, float _y)
  {
    x = _x;
    y = _y;
  }
  
  
  //add
  //add JVector vec to this vector
  public void add(JVector vec)
  {
   x += vec.x;
   y += vec.y;
  }
  
  //scalar
  //multiply this vector by a scalar
  public void scalar(float scale)
  {
   x *= scale;
   y *= scale;
  }
  
  //mag
  //get the magnitude of this vector
  public float mag()
  {
   return sqrt(pow(x,2) + pow(y,2));
  }
  
  //dist
  //gets the distance between this vector and JVector vec
  public float dist(JVector vec)
  {
   return  sqrt(pow(x - vec.x,2) + pow(y - vec.y,2));
  }
  
};
