import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int ans = 0;
    int l = 0;
    int r = s.length()-1;
    while (l <= r) {
      char lc = s.charAt(l);
      char rc = s.charAt(r);
      if (lc == rc) {
        l++;
        r--;
      } else if (lc == 'x' && rc != 'x') {
        l++;
        ans++;
      } else if (lc != 'x' && rc == 'x') {
        r--;
        ans++;
      } else {
        ans = -1;
        break;
      }
    }
    System.out.println(ans);
  }
}
