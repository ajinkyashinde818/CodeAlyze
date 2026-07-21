import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String s = scanner.next();
    if (possible(s)) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }

  private static boolean possible(CharSequence s) {
    for (int i = 0; i < s.length();) {
      if (startsWith(s, i, "dreamer")) {
        i += 5;
        if (!startsWith(s, i, "erase")) i += 2;
      } else if (startsWith(s, i, "dream")) {
        i += 5;
      } else if (startsWith(s, i, "eraser")) {
        i += 6;
      } else if (startsWith(s, i, "erase")) {
        i += 5;
      } else {
        return false;
      }
    }
    return true;
  }

  private static boolean startsWith(CharSequence s, int i, String t) {
    if (i + t.length() > s.length()) return false;
    for (int j = 0; j < t.length(); j++) {
      if (s.charAt(i + j) != t.charAt(j)) return false;
    }
    return true;
  }
}
