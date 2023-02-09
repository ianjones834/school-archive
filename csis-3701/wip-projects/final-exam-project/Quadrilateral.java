import java.util.ArrayList;

public class Quadrilateral extends Polygon {
  private ArrayList<Integer> sideLengths = new ArrayList<>();

  public Quadrilateral(int[] args) {
    super();

    this.numSides = 4;

    for (int integer : args) {
      sideLengths.add(integer);
    }
  }

  public ArrayList<Integer> getSideLengths() {
    return sideLengths;
  }
}