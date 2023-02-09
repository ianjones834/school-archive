import java.util.ArrayList;

public class Course {
  private String term;
  private String year;
  private String department;
  private String courseNumber;
  private String courseName;
  private int numEnrolled;
  private int studentCap;

  private ArrayList<Student> roster = new ArrayList<>();
  private ArrayList<Student> waitList = new ArrayList<>();

  public Course(String[] args) {
    term = args[0];
    year = args[1];
    department = args[2];
    courseNumber = args[3];
    courseName = args[4];

    try {
      studentCap = Integer.parseInt(args[5]);
    }
    catch (NumberFormatException exp) {
      exp.printStackTrace();
    }

    numEnrolled = 0;
  }

  public String getTermAndYear() {

    return this.term + " " + this.year;
  }

  public String getDeptAndNumber() {

    return this.department + " " + this.courseNumber;
  }

  public String getCourseName() {

    return this.courseName;
  }

  public boolean addStudentToRoster(Student student) {

    if (isSeatFree()) {
      this.roster.add(student);
      this.numEnrolled++;
      return true;
    }

    return false;
  }

  public boolean addStudenttoWaitlist(Student student) {

    waitList.add(student);
    return true;
  }

  public boolean dropStudentFromRoster(Student student) {

    if (isRegistered(student)) {
      this.roster.remove(student);
      this.numEnrolled--;

      while (isSeatFree() && waitList.isEmpty() == false) {
        roster.add(waitList.remove(0));
        numEnrolled++;
      }

      return true;
    }

    return false;
  }

  public void printRoster() {

    int i = 1;

    for (Student student : this.roster) {
      System.out.println(i + ": " + student.getName() + " " + student.getHNum());
      i++;
    }
  }

  public boolean isRegistered (Student student) {

    if (roster.contains(student)) {
      return true;
    }

    return false;
  }

  private boolean isSeatFree() {

    if (numEnrolled < studentCap) {
      return true;
    }

    return false;
  }
}