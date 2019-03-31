package cardgame;

public class Card {
	private String val;
	private String  suit;
	
	public Card(String val, String suit)
	{
		this.val = val;
		this.suit = suit;
	}
	
	public void display()
	{
		if(suit == "Joker")
		{
			System.out.println(suit);
		}
		else
		{
			System.out.println(val + ": " + suit);
		}
	}
}
