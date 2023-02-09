import java.math.BigDecimal;

public class Transaction {
  private TransactionType type;
  private BigDecimal amount;
  private String label;

  private Transaction(TransactionType type, BigDecimal amount, String label) {
    this.type = type;
    this.amount = amount;
    this.label = label;
  }

  public static Transaction newCredit(BigDecimal amount, String label) {
    return new Transaction(TransactionType.Credit, amount, label);
  }

  public static Transaction newDebit(BigDecimal amount, String label) {
    return new Transaction(TransactionType.Debit, amount, label);
  }

  public BigDecimal getAmount() {
    return amount;
  }

  public void setAmount(BigDecimal amount) {
    this.amount = amount;
  }

  public String getLabel() {
    return label;
  }

  public TransactionType getType() {
    return type;
  }
}