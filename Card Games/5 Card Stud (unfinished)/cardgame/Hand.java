package cardgame;
import java.util.*;

public class Hand {

	public Vector hand;
	public float money = 0;
	
	public Hand()
	{
		hand = new Vector();
	}
	
	public void showHand()
	{
		System.out.println("\nYour Hand:");
		for(int i = 0; i < hand.size(); i++)
		{
			Card c = (Card)hand.get(i);
			c.display();
		}
	}
	
	public void add(Card c)
	{
		hand.add(c);
	}
	
	
}
