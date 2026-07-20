import java.util.*;
class Main {
  public static void main(String[] args) {
    List<Integer> data = new ArrayList<>(Arrays.asList(39, 7, 4));
    Collections.sort(data);
    System.out.println(data.get(0));
  }
}
