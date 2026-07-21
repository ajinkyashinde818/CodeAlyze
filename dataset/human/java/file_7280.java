import java.util.*;

public class Main {
  public static void main(String[] args) {
    StringBuffer[] devide = {new StringBuffer("dream"), new StringBuffer("dreamer"), new StringBuffer("erase"), new StringBuffer("eraser")};
    Scanner sc = new Scanner(System.in);
    StringBuffer S = new StringBuffer(sc.next());
    S.reverse(); // 入力された文字列を反転
    for (int i = 0; i < devide.length; i++) {
      devide[i].reverse(); // devideのそれぞれの文字列を反転
    }
    boolean can = true;
    for (int i = 0; i < S.length(); ) {
      boolean can2 = false;
      for (int j = 0; j < devide.length; j++) {
        String d = new String(devide[j]);
        if (i + d.length() <= S.length() && S.substring(i, i + d.length()).equals(d)) {
          can2 = true;
          i += d.length();
        }
      }
      if (!can2) {
        can = false;
        break;
      }
    }
    if (can) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}
