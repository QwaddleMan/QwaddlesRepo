/*
Breakout

author: Jason Bowerman

This is simply the breakout game(1976) with some changes from the original. I may come back to make it 
more like the original. 
*/

import java.util.Vector;
Block paddle;
Vector< Vector<Block> > blocks;
Vector<Block> inner;
Ball b;
int lives = 4;

boolean slow = false;
boolean game = false;
boolean gameOver = false;

String lifeScore;

int bsize;
int blockW = 70;
int cols = 7;
int totalBlocks;
float spacing = 10;
int blockH = 20;
int top = 50,left = 5 ;


void setup()
{
  size(800,800);
  
  //initialize the paddle
  paddle = new Block(width/2-50,height-50,100,10,2);
  //paddle.showCollider(true);
  
  //determine quantity of blocks needed and initialize the array
  blocks = new Vector();
  bsize = (width - (blockW))/blockW;
  
  
  
  
  //initialize all the blocks
  for(int j = 0; j < cols; j++)
  {
    inner = new Vector();
    for(int i = 0; i < bsize; i++)
    {
     inner.add(new Block((i * (blockW+spacing))+left,(j*(blockH+spacing))+top, blockW,blockH,1));  
     inner.get(i).setRandomColor();
     //inner.get(i).showCollider(true);
    }
    blocks.add(inner);
  }
  
  
  //set up ball
  b = new Ball(width/2, height/2, 10);
  
  
}

void draw()
{
  background(0);
  
  //TODO: refactor all this
  
  //all this chunk does is detects collisions with blocks and does something
  //according to what collider it hits
  for(int j = 0; j < cols; j++)
  {
    for(int i = 0; i < bsize; i++)
    {
     blocks.get(j).get(i).display();
     if(b.CollidesGetName(blocks.get(j).get(i)) == "bottom")
     {
       blocks.get(j).get(i).Exists(false);
       b.addForce(new JVector(0, abs(b.getVel().y)*2));
       
     }
     
     if(b.CollidesGetName(blocks.get(j).get(i)) == "top")
     {
       blocks.get(j).get(i).Exists(false);
       b.addForce(new JVector(0,-1 * abs(b.getVel().y)*2));
     }
    }
  }
  
  //this shows your lives and score TODO: make score/////
  lifeScore = "Life: " + lives;
  textSize(24);
  fill(158,17,234);
  text(lifeScore, 10,24);
  //////////end of show lives and score ////////////////
  
  //if the ball misses the paddle then
  //lose a life and return the ball to follow the paddle
  if(b.reflectOffWindow() == "bottom")
  {
    game = false;  
    lives -= 1;
    
    if(lives < 0)
    {
      gameOver = true;
    }
    
  }
  
  //if game over present GAME OVER
  if(gameOver)
  {
    textSize(32);
    fill(255,0,0);
    text("GAME OVER", width/2-40, height/2);
    textSize(24);
    fill(255);
    text("press space to restart",width/2 - 80, height/2 + 32);
  }
  
  
  //make the ball follow the paddle if game is false
  if(!game)
  {
   b.setVel(0,0);
   b.setAcc(0,0);
   b.setPos(paddle.getPos().x + 50.0f, paddle.getPos().y - 5.0f);
  }
  
  //check if there are no more blocks and reset if there arent
  if(noMoreBlocks())
  {
    reset();
  }
  
  //collision of the ball on the paddle
  if(b.Collides(paddle))
    b.addForce(new JVector(0, -10));
    
  
  if(slow)
    paddle.Friction(.4f);//slow the paddle down after key up
  
  paddle.holdInFrame(); //keep the paddle in the frame
  
  //display and update the ball and the paddle here
  b.display();
  b.update();
  paddle.display();
  paddle.update();
}

void keyPressed()
{
   if(!gameOver)
   {
    if(keyCode == LEFT)
    {
      paddle.setVel(-10,0);
      slow = false;
    }
    if(keyCode == RIGHT)
    {
      paddle.setVel(10,0);
      slow = false;
    }
    
    if(!game && key == ' ') //space bar begins game
    {
     game = true;
     b.setVel(random(-5,5), -10); 
    }
  }
  else
  {
    if(key == ' ') //space bar begins game
    {
     reset();
    }
  }
}

//reset the game
void reset()
{
     gameOver = false;
     game = false;
     
     if(lives == -1)//if reset because of no more lives then reset lives. otherwise keep lives
       lives = 4;   //and reset blocks
     
     for(int i = 0; i < blocks.size(); i++)
     {
       for(int j = 0; j < blocks.get(i).size(); j++)
       {
         blocks.get(i).get(j).Exists(true);
         blocks.get(i).get(j).setRandomColor();
       }
     }
}

//check if there are no more blocks
//returns true if there are no more blocks
//returns false if there are blocks
boolean noMoreBlocks()
{
  for(int i = 0; i < blocks.size(); i++)
     {
       for(int j = 0; j < blocks.get(i).size(); j++)
       {
         if(blocks.get(i).get(j).getExists())
           return false;
       }
     }
     return true;
}

void keyReleased()
{
    slow = true;
}
