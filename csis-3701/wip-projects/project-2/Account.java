import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class Account {
  private List<Transaction> transactions = new ArrayList<>();
  private BigDecimal balance;

  public Account() {
    balance = BigDecimal.ZERO;
  }

  public void addTransaction(Transaction transaction) {
    transactions.add(transaction);
    setBalance();
  }

  private void setBalance() {
    BigDecimal creditSum = transactions.stream().filter(cr -> cr.getType() == TransactionType.Credit)
	    .map(Transaction::getAmount).reduce(BigDecimal.ZERO, BigDecimal::add);

    BigDecimal debitSum = transactions.stream().filter(dr -> dr.getType() == TransactionType.Debit)
	    .map(Transaction::getAmount).reduce(BigDecimal.ZERO, BigDecimal::add);

    balance = creditSum.subtract(debitSum);
  }

  public String getBalance() {
    return NumberFormat.getCurrencyInstance(Locale.US).format(balance.doubleValue());
  }
}
