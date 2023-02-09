public class Main {

	public static void main(String[] args) throws Exception {

		Game g = new Game();	
		g.printWelcome();
		g.get_player().inputPlayerName();

		for (int qNum = 0; qNum < 5; qNum++) {
			
			g.printQuestion(qNum);
			g.printChoices(qNum);
			g.get_player().inputPlayerChoice(qNum);
		}

		System.out.println( g.get_player().getPlayerName() + "'s results:" );
		g.calcScore();

	}
}