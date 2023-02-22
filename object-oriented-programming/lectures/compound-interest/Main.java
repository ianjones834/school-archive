import java.math.BigDecimal;
import java.util.Scanner;
import java.text.NumberFormat;
import java.util.Locale;

public class Main {
  public static void main(String[] args) {

    Scanner input = new Scanner(System.in);

    BigDecimal defaultPrincipal =  new BigDecimal("1000");
    BigDecimal defaultRate = new BigDecimal("0.05");
    BigDecimal userPrincipal;
    BigDecimal userRate;
    int years;

    System.out.printf("Enter the principal[1000.00]: ");
    userPrincipal = input.nextBigDecimal();

    System.out.printf("Enter the interest rate[]: ");
    userRate = input.nextBigDecimal();

    System.out.printf("Enter the number of years[10]: ");
    years = input.nextInt();

    if (userPrincipal.compareTo(BigDecimal.ZERO) > 0) {
      defaultPrincipal = userPrincipal;
    }

    if(userRate.compareTo(BigDecimal.ZERO) > 0) {
      defaultRate = userRate;
    }

    if(years <= 0) {
      years = 10;
    }

    System.out.printf("%s\t%20s\n", "Year", "Amount on deposit");

    NumberFormat USformat = NumberFormat.getCurrencyInstance(Locale.US);

    for (int count = 1; count <= years; count++) {
      BigDecimal amount = defaultPrincipal.multiply(defaultRate.add(BigDecimal.ONE).pow(count));
      System.out.printf("%-4d\t", count);
      System.out.printf("%20s\n", USformat.format(amount));
    }
  }
}