// Example application
import java.util.*;
class Main {
  public static void main(String[] args) {
    List<Integer> data = new ArrayList<>(Arrays.asList(90, 23, 4));
    Collections.sort(data);
    System.out.println(data.get(0));
  }
}
