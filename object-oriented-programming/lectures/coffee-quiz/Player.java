import java.util.Scanner;

public class Player {
	Scanner scan = new Scanner(System.in);

	private String playerName;
	private int[] playerAnswers = new int[5];

	public String getPlayerName() {
		return playerName;
	}

	public int getPlayerAnswer(int qNum) {
		return playerAnswers[qNum-1];
	}

	public void inputPlayerName() {
		do {
			System.out.println("Please enter your name:");
			playerName = scan.nextLine();
		}while (this.playerName.equals(""));
	}

	public void inputPlayerChoice(int qNum) {
		boolean valid = false;
		do {
			System.out.println("Enter your answer:");
			playerAnswers[qNum] = scan.nextInt();
			playerAnswers[qNum] = playerAnswers[qNum]-1;

		if(playerAnswers[qNum] >= 0 && playerAnswers[qNum] <= 3){
				valid = true;
			}else{
				System.out.println("Please choose a number between 1 and 4");
			}
		}while (!valid);


	}


}
