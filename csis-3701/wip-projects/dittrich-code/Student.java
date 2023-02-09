public class Student {

  private String firstName;
  private String lastName;
  private String uid;

  public Student(String fname, String lname, String ynum){
    this.firstName = fname;
    this.lastName = lname;
    this.uid = ynum;
  }

  public void setFirstName(String fname){
    this.firstName = fname;
    return;
  }

  public void setLastName(String lname){
    this.lastName = lname;
    return;
  }

  public String getName(){
    return this.firstName + " " + this.lastName;
  }

  public String getUid(){
    return this.uid;
  }

}