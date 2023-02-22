public abstract class Polygon {
  protected int numSides;

  public int calcAngleSum() {
    return (this.numSides - 2) * 180;
  }
}
