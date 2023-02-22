public class Game {

	private Player _player;
	private Question[] q = new Question[5];
	
	public Game() throws Exception {

		_player = new Player();
		
	    initQuestions();
	}
	

	public Player get_player() {
		return _player;
	}

	public void printWelcome() {
		System.out.println("Welcome To Trivia Game!");
	}
	 
	public void initQuestions() throws Exception {

		q[0] = new Question ("What is the capital of Canada?", 1, 0);
		q[0].setChoices ("Ottawa", "Vancouver", "Toronto" ,"Edmonton");
	
		q[1] = new Question ("What is the capital of Spain?", 2, 1);
		q[1].setChoices ("Málaga", "Barcelona", "Madrid", "Murcia");
	
		q[2] = new Question ("What is the capital of Thailand?", 3, 2);
		q[2].setChoices ("Krabi", "Phuket", "Bangkok", "Pattaya City");
	
		q[3] = new Question ("What is the capital of Hungary?", 4, 1);
		q[3].setChoices ("Miskolc", "Budapest", "Debrecen", "Szeged");
	
		q[4] = new Question ("What is the capital of Texas?", 5, 3);
		q[4].setChoices ("Dallas", "Houston", "San Antonio", "Austin");
	
	}

	public void printQuestion(int qNum) {
		System.out.println( q[qNum].getNumber() + ". " + q[qNum].getText() );
	}

	public void printChoices(int qNum) {
		q[qNum].printAnswers();
	}

	public void calcScore() {
		int totalCorrect = 0;
		int totalQuestions = 5;

		for(int i = 0; i < totalQuestions; i++) {
			if(q[i].isCorrectAnswer(this.get_player())){
				totalCorrect++;
			}
		}

		double finalScore = (100 * totalCorrect) / totalQuestions;
		System.out.println("Your score is: " + finalScore + "%");
	}

}
