import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class StudentBody {

  private ArrayList<Student> students = new ArrayList<>();

  public StudentBody() {
    initStudentBody();
  }

  private void initStudentBody() {
    students = new ArrayList<>();
    Path studentFilePath = Paths.get("./students.txt");


    try (Scanner fileInput = new Scanner(studentFilePath)) {
      String pattern = "(\\w+)\\s+(\\w+)\\s+([0-9]{1,})\\s?";
      Pattern r = Pattern.compile(pattern);

      while (fileInput.hasNextLine()) {
        String studentString = fileInput.nextLine();

        Matcher m = r.matcher(studentString);

        if (m.find()) {
          String[] studentInfo = {
            m.group(1),
            m.group(2),
            m.group(3),
          };

          this.addStudent(studentInfo);
        }
      }
    }
    catch (IOException e) {
      e.printStackTrace();
    }
  }

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