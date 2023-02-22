import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

  static Scanner input = new Scanner(System.in);
  static CourseCatalog catalog = new CourseCatalog();
  static StudentBody body = new StudentBody();

  public static void main(String[] args) {
    startRegistration();
  }

  private static void startRegistration() {

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
      Course course = catalog.getCourse(collectCourseSearchInfo());
      String uId = collectStudentSearchInfo();

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
    else if (userCommand.equals("f")) {
      Student student = body.getStudent(collectStudentSearchInfo());

      if (student == null) {
        System.out.println("Error: Student is not Enrolled\n");
        return;
      }

      student.finalizeSchedule();
    }
    else if (userCommand.equals("a")) {
      Student student = body.getStudent(collectStudentSearchInfo());

      if (student == null) {
        System.out.println("Error: Student is not Enrolled\n");
        return;
      }

      System.out.print("Enter positive payment amount: $");
      BigDecimal payment = new BigDecimal(input.next());
      System.out.println();

      if (payment.compareTo(BigDecimal.ZERO) < 0) {
        payment = payment.negate();
      }

      student.addPayment(payment);
    }
    else if (userCommand.equals("b")) {
      Student student = body.getStudent(collectStudentSearchInfo());

      if (student == null) {
        System.out.println("Error: Student is not Enrolled\n");
        return;
      }

      System.out.println(student.getStudentAccountBalance());
      System.out.println();
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
    System.out.println("f - Finalize a Student Schedule");
    System.out.println("a - Add a Payment to a Student Account");
    System.out.println("b - Print a Student Balance");
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