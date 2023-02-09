import java.io.IOException;
import java.util.List;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
  public static void main(String[] args) {
    List<CatalogItem> catalog = new ArrayList<>();
    Path catalogPath = Paths.get("./catalog_items.csv");

    String[] availableColors = {
      "Red",
      "Orange",
      "Yellow",
      "Green",
      "Blue",
      "Purple",
      "Pink",
      "White",
      "Black"
    };

    try (Scanner fileInput = new Scanner(catalogPath)) {
      String pattern = "([A-Za-z]+)\\,([[A-Za-z]+\\s?]+)\\,([A-Za-z]+)\\,([0-9]+)";
      Pattern r = Pattern.compile(pattern);

      while (fileInput.hasNextLine()) {
        String catalogItemString = fileInput.nextLine();

        Matcher m = r.matcher(catalogItemString);

        if (m.find()) {
          CatalogItem catalogItem = new CatalogItem(m.group(1), m.group(2), m.group(3), Integer.parseInt(m.group(4)));
          catalog.add(catalogItem);
        }
      }
    }
    catch (IOException e) {
      e.printStackTrace();
    }

    catalog.removeIf(ci -> {
      for (String color : availableColors) {
        if (ci.getColor().equals(color)) {
          return false;
        }
      }

      return true;
    });

    System.out.println("Number of disctinct items per color:");

    for (String color : availableColors) {
      long count = catalog.stream()
        .filter(ci -> ci.getColor().equals(color))
        .distinct()
        .count();

      System.out.print(color);
      System.out.print(": ");
      System.out.println(count);
    }


  }
}
