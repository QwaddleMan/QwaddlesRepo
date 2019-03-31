package cardgame;

public class Source {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Deck deck = new Deck();
		deck.shuffle();
		deck.showCards();
		Card[] hand = deck.deal(5);
		
		System.out.println("\nYour hand: ");
		for(int i = 0; i < hand.length; i++)
		{
			if(hand[i] != null)
				hand[i].display();
		}
	}

}
