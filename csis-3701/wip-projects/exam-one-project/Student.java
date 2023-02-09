public class Student {

  private String firstName;
  private String lastName;
  private String hNum;

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
}