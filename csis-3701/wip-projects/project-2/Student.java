import java.math.BigDecimal;

public class Student {

  private String firstName;
  private String lastName;
  private String hNum;
  private int numCredits = 0;

  private Account account = new Account();

  public Student(String[] args) {
    this.firstName = args[0];
    this.lastName = args[1];
    this.hNum = args[2];
  }

  public String getName() {
    return firstName + " " + lastName;
  }

  public String getHNum() {
    return this.hNum;
  }

  public void setFirstName(String fName) {
    this.firstName = fName;
  }

  public void setLastName(String lName) {
    this.lastName = lName;
  }

  public void setHNum(String id) {
    this.hNum = id;
  }

  public void addCredits(int numCredits) {
    this.numCredits += numCredits;
  }

  public void removeCredits(int numCredits) {
    this.numCredits -= numCredits;
  }

  public void addPayment(BigDecimal payment) {
    account.addTransaction(Transaction.newCredit(payment, "payment"));
  }

  public void finalizeSchedule() {
    BigDecimal tuition;

    if (numCredits > 11 && numCredits < 19) {
      tuition = new BigDecimal(3240);
    }
    else {
      tuition = new BigDecimal(numCredits * 270);
    }

    account.addTransaction(Transaction.newDebit(tuition, "tuition"));
  }

  public String getStudentAccountBalance() {
    return account.getBalance();
  }
}