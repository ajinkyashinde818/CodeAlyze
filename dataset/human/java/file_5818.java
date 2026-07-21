import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String S = sc.next();

    char[] s = S.toCharArray();
    Arrays.sort(s);
    String result = String.valueOf(s).equals("abc") ? "Yes" : "No";

    System.out.println(result);

  }
}
