import java.util.Scanner;

public class Addition {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("Enter your first integer: ");
		int i = input.nextInt();

		System.out.print("Enter your second integer: ");
		int j = input.nextInt();

		int sum = i + j;

		System.out.printf("Sum is %d%n", sum);
	}
}