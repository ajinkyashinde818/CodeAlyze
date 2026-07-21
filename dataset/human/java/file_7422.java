import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.lang.Integer;
import java.lang.StringBuilder;
import java.lang.Math;

public class Main {
  private static char[] DREAMER = new String("dreamer").toCharArray();
  private static char[] DREAM = new String("dream").toCharArray();
  private static char[] ERASE = new String("erase").toCharArray();
  private static char[] ERASER = new String("eraser").toCharArray();

  private static boolean startsWith(char[] s, char[] target, int current) {
    int i = 0;
    while (current + i < target.length && i < s.length) {
      if (s[i] != target[current + i]) {
        return false;
      }

      i++;
    }

    return i == s.length;
  }

  public static boolean isDayDreamInternal(char[] s, int current) {
    if (current == s.length) return true;
    if (current >= s.length - 4) return false;

    if (startsWith(DREAMER, s, current)) {
      if (isDayDreamInternal(s, current + 7)) {
        return true;
      }
    }

    if (startsWith(ERASER, s, current)) {
      if (isDayDreamInternal(s, current + 6)) {
        return true;
      }
    }

    if (startsWith(ERASE, s, current) || startsWith(DREAM, s, current)) {
      if (isDayDreamInternal(s, current + 5)) {
        return true;
      }
    }

    return false;
  }

  public static boolean isDayDream(char[] s) {
    return isDayDreamInternal(s, 0);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    char[] s = in.next().toCharArray();

    boolean result = isDayDream(s);

    if (result) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
    //System.out.println(s.substring(s.length()));
  }
}
