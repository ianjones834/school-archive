import java.util.Scanner;

public class Comparison {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("Enter first integer: ");
		int numberOne = input.nextInt();

		System.out.print("Enter second integer: ");
		int numberTwo = input.nextInt();

		if(numberOne == numberTwo) {
			System.out.printf("%d == %d%n", numberOne, numberTwo);
		}

		if(numberOne != numberTwo) {
			System.out.printf("%d != %d%n", numberOne, numberTwo);
		}

		if(numberOne < numberTwo) {
			System.out.printf("%d < %d%n", numberOne, numberTwo);
		}

		if(numberOne <= numberTwo) {
			System.out.printf("%d <= %d%n", numberOne, numberTwo);
		}

		if(numberOne > numberTwo) {
			System.out.printf("%d > %d%n", numberOne, numberTwo);
		}

		if(numberOne >= numberTwo) {
			System.out.printf("%d >= %d%n", numberOne, numberTwo);
		}
	}
}