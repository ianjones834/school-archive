import java.util.ArrayList;

public class CourseCatalog {

  private ArrayList<Course> courses = new ArrayList<>();

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