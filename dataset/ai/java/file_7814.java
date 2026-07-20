import java.util.*;
class Main {
  public static void main(String[] args) {
    List<Integer> data = new ArrayList<>(Arrays.asList(24, 19, 8));
    Collections.sort(data);
    System.out.println(data.get(0));
  }
}
