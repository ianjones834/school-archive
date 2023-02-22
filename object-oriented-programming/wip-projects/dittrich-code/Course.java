import java.util.ArrayList;

public class Course {

  private String term;
  private String year;
  private String dept;
  private String number;
  private String name;
  private int enrolled;
  private int cap;
  private ArrayList<String> roster =  new ArrayList<>();

  public Course(String[] args) {
    term = args[0];
    year = args[1];
    dept = args[2];
    number = args[3];
    name = args[4];
    try{
      cap = Integer.parseInt(args[5]);
    }catch (NumberFormatException e){
      e.printStackTrace();
    }
    enrolled = 0;
  }

  public String getTermAndYear(){
    return this.term + this.year;
  }

  public String getDeptAndNumber(){
    return this.dept + " " + this.number;
  }

  public String getCourseName(){
    return this.name;
  }

  public boolean addStudent(String uid){
    if(enrolled < cap){
      roster.add(uid);
      enrolled++;
      return true;
    }else{
      System.out.println("Cannot enroll student: enrollment exceeds cap");
    }
    return false;
  }

  public boolean dropStudent(String uid){
    if(roster.contains(uid)){
      roster.remove(uid);
      enrolled--;
      return true;
    }else{
      System.out.println("Cannot drop student: ID " + uid + " is not present in roster.");
    }
    return false;
  }

  public void printRoster(){
    int i = 1;
    for(String item: this.roster) {
      System.out.println(i + ". " + item);
      i++;
    }
    return;
  }

}