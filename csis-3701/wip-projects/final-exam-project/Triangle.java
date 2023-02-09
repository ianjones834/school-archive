import java.util.ArrayList;

public class Triangle extends Polygon {
  private ArrayList<Integer> sideLengths = new ArrayList<>();

  public Triangle(int[] args) {
    super();

    this.numSides = 3;

    for (int integer : args) {
      sideLengths.add(integer);
    }
  }

  public ArrayList<Integer> getSideLengths() {
    return sideLengths;
  }

}
