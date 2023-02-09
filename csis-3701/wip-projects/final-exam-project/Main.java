import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
  private static List<Triangle> triangleList = new ArrayList<>();
  private static List<Quadrilateral> quadrilateralList = new ArrayList<>();

  public static void main(String[] args) {

    Path sidePath = Paths.get("./polygons.txt");

    try (Scanner fileInput  = new Scanner(sidePath)) {
      String pattern = "(\\w),(.+)";
      Pattern r = Pattern.compile(pattern);

      while (fileInput.hasNextLine()) {
        String polygonSidesString = fileInput.nextLine();

        Matcher m = r.matcher(polygonSidesString);

        if (m.find()) {
          if (m.group(1).equals("T")) {
            int[] sideLengths = new int[3];

            String[] stringSideLengths = m.group(2).split(",");

            for (int i = 0; i < 3; i++) {
              sideLengths[i] = Integer.parseInt(stringSideLengths[i]);
            }

            triangleList.add(new Triangle(sideLengths));
          }
          else {
            int[] sideLengths = new int[4];

            String[] stringSideLengths = m.group(2).split(",");

            for (int i = 0; i < 4; i++) {
              sideLengths[i] = Integer.parseInt(stringSideLengths[i]);
            }

            quadrilateralList.add(new Quadrilateral(sideLengths));
          }
        }
      }
    }
    catch (IOException e) {
      e.printStackTrace();
    }

    System.out.println("The Internal Angles of all Triangles should be 180:");

    int count = 1;

    for (Triangle triangle : triangleList) {
      System.out.println("Triangle " + count + ": " + triangle.calcAngleSum());
    }

    System.out.println("\nThe Internal Angles of all Quadrilaterals should be 360:");

    count = 1;

    for (Quadrilateral quadrilateral : quadrilateralList) {
      System.out.println("Quadrilateral " + count + ": " + quadrilateral.calcAngleSum());
      count++;
    }

    System.out.println("\nAverage side length of triangles: ");
    List<Double> averageSideLengthList = triangleList
      .stream()
      .map(Triangle::getSideLengths)
      .map(sideLengthArray -> {
        return sideLengthArray.stream().mapToInt(x -> x).average().getAsDouble();
      })
      .toList();

    count = 1;

    for (double average : averageSideLengthList) {
      System.out.println("Triangle " + count + ": " + average);
      count++;
    }

    System.out.println("\nAverage side length of quadrilaterals: ");
    averageSideLengthList = quadrilateralList
      .stream()
      .map(Quadrilateral::getSideLengths)
      .map(sideLengthArray -> {
        return sideLengthArray.stream().mapToInt(x -> x).average().getAsDouble();
      })
      .toList();

    count = 1;

    for (double average : averageSideLengthList) {
      System.out.println("Quadilateral " + count + ": " + average);
      count++;
    }
  }
}