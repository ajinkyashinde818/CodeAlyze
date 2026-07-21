import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    sc.close();

    String result;
    if (s.matches("^(dream|dreamer|erase|eraser)*$")) {
      result = "YES";
    } else {
      result = "NO";
    }
    System.out.println(result);
  }
}
