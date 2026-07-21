import java.util.*;

public class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    char[] ss = s.toCharArray();
    char[] tt = t.toCharArray();
    Arrays.sort(ss);
    Arrays.sort(tt);
    for (int i=0; i<tt.length / 2; i++) {
      char tmp = tt[i];
      tt[i] = tt[tt.length-1-i];
      tt[tt.length-1-i] = tmp;
    }
    int check =0,y =0, w=0;
    for (int i=0; i<Math.min(ss.length,tt.length); i++) {
      if (ss[i] < tt[i]) {
        y++;
        break;
      }
      if (ss[i] > tt[i]) {
        w++;
        break;
      }
    }
    if (y != 0) {
      System.out.println("Yes");
    } else if (w != 0) {
      System.out.println("No");
    } else if (ss.length < tt.length) {
      System.out.println("Yes");      
    } else {
      System.out.println("No");
    }
  }
}
