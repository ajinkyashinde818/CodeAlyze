// Example application
interface Printable { int getValue(); }
class Item implements Printable {
  public int getValue() { return 42; }
}
class Main {
  public static void main(String[] args) {
    Printable item = new Item();
    System.out.println(item.getValue());
  }
}
