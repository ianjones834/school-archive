import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;;

public class CourseCatalog {

  private ArrayList<Course> courses;

  public CourseCatalog() {
    initCourseCatalog();
  }

  private void initCourseCatalog() {
    courses = new ArrayList<>();
    Path coursesPath = Paths.get("./courses.txt");

    try (Scanner fileInput = new Scanner(coursesPath)) {
      String pattern = "(Fall|Summer|Spring)\\s+(2[0-9]{3})\\s+([A-Z]{3,})\\s+([1-5][0-9]{3})\\s+(([A-Za-z-]+\\s)+([A-Za-z]+))\\s+([0-9]{1,})\\s+([0-9]{1,})";
      Pattern r = Pattern.compile(pattern);

      while (fileInput.hasNextLine()) {
        String courseString = fileInput.nextLine();

        Matcher m = r.matcher(courseString);

        if (m.find()) {
          String[] courseInfo = {
            m.group(1),
            m.group(2),
            m.group(3),
            m.group(4),
            m.group(5),
            m.group(8),
            m.group(9)
          };

          this.addCourse(courseInfo);
        }
      }
    }
    catch (IOException e) {
      e.printStackTrace();
    }
  }

  public void addCourse(String[] args) {
    Course newCourse = new Course(args);
    this.courses.add(newCourse);
  }

  public Course getCourse (String[] args) {
    for (Course course : this.courses) {
      if (course.getDeptAndNumber().equals(args[2] + " " + args[3]) && course.getTermAndYear().equals(args[0] + " " + args[1])) {
        return course;
      }
    }

    return null;
  }

  public void printCatalog() {
    int i = 1;

    for (Course course : this.courses) {
      System.out.println(i + ": " + course.getTermAndYear() + " " + course.getDeptAndNumber() + " " + course.getCourseName());
      i++;
    }

  }
}
