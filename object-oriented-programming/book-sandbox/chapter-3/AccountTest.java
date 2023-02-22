import java.util.Scanner;

public class AccountTest {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		Account account1 = new Account("Ian Jones", 1000.0);
		Account account2 = new Account("Molly Burke", -7.13);

		System.out.printf("Initial name is: %s%n%n", account1.getName());
		
		System.out.println("Please enter a name");
		String theName = input.nextLine();
		account1.setName(theName);
		System.out.println();

		System.out.printf("Name in object myAccount %n%s%n", account1.getName());
	}
}