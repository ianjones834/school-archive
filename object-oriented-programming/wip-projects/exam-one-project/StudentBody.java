import java.util.ArrayList;

public class StudentBody {

  private ArrayList<Student> students = new ArrayList<>();

  public void addStudent(String[] args) {
    Student newStudent = new Student(args);
    students.add(newStudent);
  }

  public Student getStudent(String uId) {
    for (Student student : students) {
      if (student.getHNum().equals(uId)) {
        return student;
      }
    }

    return null;
  }

  public boolean isStudentEnrolled(String uId) {
    for (Student student : students) {
      if (student.getHNum().equals(uId)) {
        return true;
      }
    }

    return false;
  }
}