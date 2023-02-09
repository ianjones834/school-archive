public class CatalogItem {

  private String color;
  private String item;
  private String category;
  private int quantity;

  public CatalogItem(String color, String item, String category, int quantity) {
    this.color = color;
    this.item = item;
    this.category = category;
    this.quantity = quantity;
  }

  public String getColor() {
    return color;
  }

  public String getItem() {
    return item;
  }

  public String getCategory() {
    return category;
  }

  public int getQuantity() {
    return quantity;
  }

  @Override
  public String toString() {
    return String.format("\s,\s,\s,\s", color, item, category, quantity);
  }
}
