package cardgame;

import java.util.Stack;
import java.util.concurrent.ThreadLocalRandom;

public class Deck {
	public Stack<Card> deck;
	
	public Deck()
	{
		deck = new Stack<Card>();
		getPlayingCards();
	}
	
	public void getPlayingCards()
	{
		String suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
		String val = "";
		
		for(int i = 0; i < 4; i++)
		{
			for(int j = 2; j < 15; j++)
			{
				val = "";
				if(j < 10)
				{
					val += ((char)(j+48));
				}
				else if(j == 10)
				{
					val = "10";
				}
				else
				{
					switch(j) {
					case 11: val = "J"; break;
					case 12: val = "Q"; break;
					case 13: val = "K"; break;
					case 14: val = "A"; break;
					}
				}
				
				deck.push(new Card(val, suits[i]));
			}
		}
		
		//jokers
		deck.push(new Card("", "Joker"));
		deck.push(new Card("", "Joker"));
	}
	
	public void showCards()
	{
		Object [] cards = deck.toArray();
		Card current = new Card("","");
		for(int i = 0; i < cards.length; i++)
		{
			current = (Card)cards[i];
			current.display();
		}
	}
	
	
	public void shuffle()
	{
		
		
		Object temp = new Object();
		
		Object[] shuffledDeck = deck.toArray();
		
		//shuffle
		for(int i = 0; i < shuffledDeck.length; i++)
		{
			int swapIndex = ThreadLocalRandom.current().nextInt(0, shuffledDeck.length);
			
			temp = shuffledDeck[i];
			shuffledDeck[i] = shuffledDeck[swapIndex];
			shuffledDeck[swapIndex] = temp;
			
		}
		
		//put the cards back
		deck = new Stack<Card>();
		for(int i = 0; i < shuffledDeck.length; i++)
		{
			deck.push((Card)shuffledDeck[i]);
		}
	}
	
	public Card[] deal(int amt)
	{
		System.out.println("\ndealing...");
		Card[] hand = new Card[amt];
		for(int i = 0; i < amt; i++)
		{
			if(deck.empty())
			{
				System.out.println("no more cards...");
				break;
			}
			else
			{
				hand[i] = deck.pop();
			}
		}
		//System.out.println("Cards left in deck = " + deck.size());
		return hand;
	}
	
	
}
