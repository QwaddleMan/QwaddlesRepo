import cardgame.*;

public class Source {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Deck deck = new Deck();
		deck.shuffle();
		deck.showCards();
		
		
		Hand myhand = deck.dealHand(5);
		Hand computer = deck.dealHand(5);
		
		myhand.showHand();
		
		
	}

}
