import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		boolean flag = true;
		boolean remoteFlag = false;
		Scanner scan = new Scanner(System.in);

		System.out.println("Television and Remote Demo");
		System.out.println();

		Television televisionOne = new Television("7589");
		Television televisionTwo = new Television("7589");
		Television televisionThree = new Television("3648");

		Remote remoteOne = new Remote(televisionOne.getTvCode());
		Remote remoteTwo = new Remote(televisionTwo.getTvCode());

		ArrayList<Television> tvs = new ArrayList<>();
		ArrayList<Remote> remotes = new ArrayList<>();

		tvs.add(televisionOne);
		tvs.add(televisionTwo);
		tvs.add(televisionThree);

		remotes.add(remoteOne);
		remotes.add(remoteTwo);

		while (flag) {
			displayMenu();

			String remoteChoice = scan.next();
			System.out.println();

			if (remoteChoice.equals("q") ) {
				flag = false;
			}
			else if (remoteChoice.equals("1") || remoteChoice.equals("2")) {
				remoteFlag = true;
			}
			else {
				System.out.println("Enter a valid input");
				System.out.println();
			}

			while (remoteFlag)  {
				displayRemoteMenu();

				String command = scan.next();
				System.out.println();

				if (command.equals("q")) {
					remoteFlag = false;
				}
				else {
					try {
						Button buttonCommand = Button.valueOf(command);
						remotes.get(Integer.parseInt(remoteChoice) - 1).input(buttonCommand, tvs);
					}
					catch (IllegalArgumentException excp) {
						System.out.println("Invalid Command Enter from the List");
						System.out.println();
					}
				}
			}
		}
	}

	private static void displayMenu() {
		System.out.println("1 - Select Remote One");
		System.out.println("2 - Select Remote Two");
		System.out.println("q - Quit Program");
		System.out.println();
		System.out.print("Enter your choice: ");
	}

	private static void displayRemoteMenu() {
		System.out.println("p  - Switch Power");
		System.out.println("i - Increment Volume");
		System.out.println("o - Decrement Volume");
		System.out.println("m  - Switch Mute");
		System.out.println("u - Increment Channel");
		System.out.println("d - Decrement Channel");
		System.out.println("c - Enter Channel");
		System.out.println("f  - Previous Channel");
		System.out.println("q  - Select Different Remote");
		System.out.println();
		System.out.print("Enter your choice: ");
	}
};