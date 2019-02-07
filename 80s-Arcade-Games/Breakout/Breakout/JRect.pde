public class JRect{
  
  private float x, y, w, h;
  private String name = "null";
  
  JRect(float _x, float _y, float _w, float _h)
  {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }
  
    JRect(float _x, float _y, float _w, float _h, String Name)
  {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    name = Name;
  }
  
  
  public void setRectName(String Name)
  {
    name = Name;
  }
  
  public String getRectName()
  {
    return name;
  }
  
  //setRect
  //set the rectangle to something different than what was constructed
  public void setRect(float _x, float _y, float _w, float _h)
  {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }
  
  //getX
  //return the x position of the rect
  public float getX()
  {
    return x;
  }
  
  //getY
  //return the y positino of the rect
  public float getY()
  {
    return y;
  }
  
  //getWidth
  //return the width of the rect
  public float getWidth()
  {
    return w;
  }
  
  //getheight
  //return the height of the rect
  public float getHeight()
  {
    return h;
  }
  
  //overlap
  //determins if this rect overlaps with rect r
  public boolean overlaps(JRect r)
  {
    //checks top-left top-right bottom-left bottom-right left right top bottom
    
    if(x > r.getX() && x < r.getX() + r.getWidth() && y > r.getY() && y < r.getY() + r.getHeight())
      return true;
    else if(x+w > r.getX() && x + w < r.getX() + r.getWidth() && y > r.getY() && y < r.getY() + r.getHeight())
      return true;
    else if(x > r.getX() && x < r.getX() + r.getWidth() && y + h > r.getY() && y+h < r.getY() + r.getHeight())
      return true;
    else if (x+w > r.getX() && x+w < r.getX() + r.getWidth() && y+h > r.getY() && y+h < r.getY() + r.getHeight())
      return true;
    else if(x+w/2 > r.getX() && x+w/2 < r.getX() + r.getWidth() && y+h > r.getY() && y+h < r.getY() + r.getHeight())
      return true;
    else if(x+w/2 > r.getX() && x+w/2 < r.getX() + r.getWidth() && y > r.getY() && y < r.getY() + r.getHeight())
      return true;
    else if(x > r.getX() && x < r.getX() + r.getWidth() && y+h/2 > r.getY() && y+h/2 < r.getY() + r.getHeight())
      return true;
    else if(x+w > r.getX() && x+w < r.getX() + r.getWidth() && y+h/2 > r.getY() && y+h/2 < r.getY() + r.getHeight())
      return true;
    else
      return false;
  }
  
  
};
