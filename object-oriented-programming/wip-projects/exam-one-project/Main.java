import java.util.Scanner;

public class Main {

  static Scanner input = new Scanner(System.in);
  static CourseCatalog catalog = new CourseCatalog();
  static StudentBody body = new StudentBody();

  public static void main(String[] args) {

    String[] courseOneParams = {"Fall", "2022", "CSIS", "3701", "Advanced Object Oriented Programming", "3"};
    String[] courseTwoParams = {"Spring", "2023", "CSIS", "3700", "Data Structures and Objects", "2"};
    String[] courseThreeParams = {"Spring", "2023", "CSIS", "2610", "Programming and Problem Solving", "4"};

    catalog.addCourse(courseOneParams);
    catalog.addCourse(courseTwoParams);
    catalog.addCourse(courseThreeParams);

    String[] studentOneParams = {"Ian", "Jones", "4589"};
    String[] studentTwoParams = {"Matthew", "Jones", "1468"};
    String[] studentThreeParams = {"Megan", "Mills", "4126"};
    String[] studentFourParams = {"Molly", "Burke", "6392"};

    body.addStudent(studentOneParams);
    body.addStudent(studentTwoParams);
    body.addStudent(studentThreeParams);
    body.addStudent(studentFourParams);

    userChoiceMenu();
  }

  private static void userChoiceMenu() {

    String userCommand = "";

    while (true) {
      displayChoiceMenu();
      userCommand = input.next();

      System.out.println();
      input.nextLine();

      if (userCommand.equals("q")) {
        break;
      }

      decisionController(userCommand);
    }
  }

  private static void decisionController(String userCommand) {

    if (userCommand.equals("c")) {

      catalog.printCatalog();
      System.out.println();
    }
    else if (userCommand.equals("s")) {

      String uId = collectStudentSearchInfo();

      if (body.isStudentEnrolled(uId) == false) {
        System.out.println("This Student is not Enrolled\n");
        return;
      }

      System.out.println("This Student is Enrolled\n");
    }
    else if (userCommand.equals("p")) {

      String[] courseInfo = collectCourseSearchInfo();
      Course course = catalog.getCourse(courseInfo);

      if (course == null) {
        System.out.println("Error: Entered Course is not in the Catalog\n");
        return;
      }

      course.printRoster();
      System.out.println();
    }
    else if (userCommand.equals("r")) {

      String[] courseInfo = collectCourseSearchInfo();
      String uId = collectStudentSearchInfo();

      Course course = catalog.getCourse(courseInfo);
      Student student = body.getStudent(uId);

      if (course == null) {
        System.out.println("Error: Entered Course is not in the Catalog\n");
        return;
      }

      if (student == null) {
        System.out.println("Error: Student is not Enrolled\n");
        return;
      }

      if (course.isRegistered(student)) {
        System.out.println("Error: Student is Already Registered\n");
        return;
      }

      if (course.addStudentToRoster(student)) {
        System.out.println("Successfully Added Student\n");
      }
      else {
        System.out.println("Enrollment Exceeds Cap");
        System.out.print("Would you like to join the waitlist? ('y' if yes): ");
        String waitListCommand = input.next();
        System.out.println();

        input.nextLine();

        if (waitListCommand.equals("y")) {
          course.addStudenttoWaitlist(student);
          System.out.println("Successfully Added Student to Waitlist\n");
        }
        else {
          System.out.println("Student Not Added to Waitlist\n");
        }
      }
    }
    else if (userCommand.equals("d")) {

      String[] courseInfo = collectCourseSearchInfo();
      String uId = collectStudentSearchInfo();

      Course course = catalog.getCourse(courseInfo);

      if (course == null) {
        System.out.println("Error: Entered Course is not in the Catalog\n");
        return;
      }

      if(course.dropStudentFromRoster(body.getStudent(uId))) {
        System.out.println("Successfully Dropped Student\n");
      }
      else {
        System.out.println("Error: Entered Student is not in the Roster\n");
      }
    }
    else {

      System.out.println("Error: Enter a valid input\n");
    }
  }

  private static void displayChoiceMenu() {
    System.out.println("Choose one of the following:");
    System.out.println("c - Print Course Catalog");
    System.out.println("s - Check if a Student is Enrolled");
    System.out.println("p - Print the Course Roster");
    System.out.println("r - Register a Student for a Course");
    System.out.println("d - Drop a Student from a Course");
    System.out.println("q - Quit Program\n");
    System.out.print("Enter your choice: ");
  }

  private static String[] collectCourseSearchInfo() {
    String[] courseInfo = new String[4];

    System.out.print("Enter the Term and Year: ");
    courseInfo[0] = input.next();
    courseInfo[1] = input.next();

    input.nextLine();

    System.out.print("Enter the Department and Course Number: ");
    courseInfo[2] = input.next();
    courseInfo[3] = input.next();

    System.out.println();
    input.nextLine();

    return courseInfo;
  }

  private static String collectStudentSearchInfo() {
    System.out.print("Enter the Unique Id: ");
    String uId = input.next();

    System.out.println();
    input.nextLine();

    return uId;
  }
}