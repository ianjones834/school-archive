import java.util.Scanner;

// example object messaging

public class Main {
  public static void main(String[] args) {

    String[] course_params = {"F","2022","CSIS","3701","Advanced Object Oriented Programming","32"} ;

    Course csis3701 = new Course(course_params);
    Student ex1 = new Student("Jane","Doe","Y00123456");

    // ex1.setFirstname("Jane");
    // ex1.setLastname("Doe");
    // ex1.setUid("Y00123456");

    Student ex2 = new Student("John","Smith","Y00234567");

    // ex2.setFirstname("John");
    // ex2.setLastname("Smith");
    // ex2.setUid("Y00234567");

    Student[] students = {ex1, ex2};

    Scanner scan = new Scanner(System.in);

    System.out.println("Using individual variables:");
    System.out.println(ex1.getName());
    System.out.println(ex2.getName());

    System.out.println("\nUsing array:");
    System.out.println(students[0].getName());
    System.out.println(students[1].getName());

    System.out.println("\nUsing Course methods:");
    System.out.println(csis3701.getCourseName());
    System.out.println(csis3701.getTermAndYear());
    System.out.println(csis3701.getDeptAndNumber());

    csis3701.addStudent(ex1.getUid());
    csis3701.addStudent(students[1].getUid());

    System.out.println("\nCurrent Roster:");
    csis3701.printRoster();

    csis3701.dropStudent(ex2.getUid());
    System.out.println("\nCurrent Roster:");
    csis3701.printRoster();

    return;
  }
}