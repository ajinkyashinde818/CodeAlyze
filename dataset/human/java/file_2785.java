import java.util.*;
public class Main {
  public static void main(String...args) {
    final Scanner sc = new Scanner(System.in);
    final char[] s = sc.next().toCharArray();
    final char[] t = sc.next().toCharArray();
    Arrays.sort(s);
    Arrays.sort(t);
    final int ans = new String(s).compareTo(new StringBuilder(new String(t)).reverse().toString());
    System.out.println(ans < 0 ? "Yes" : "No");
  }
}
