import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    char[] s = scanner.next().toCharArray();
    char[] t = scanner.next().toCharArray();
    if (possible(s, t)) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }

  private static boolean possible(char[] s, char[] t) {
    Arrays.sort(s);
    Arrays.sort(t);
    reverse(t);
    for (int i = 0; i < s.length && i < t.length; i++) {
      if (s[i] < t[i]) return true;
      if (s[i] > t[i]) return false;
    }
    return s.length < t.length;
  }

  private static void reverse(char[] a) {
    int i = 0;
    int j = a.length - 1;
    while (i < j) {
      char tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    }
  }
}
