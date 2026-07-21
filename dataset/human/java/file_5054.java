import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    int Q = sc.nextInt();
    int[] T = new int[Q];
    int[] F = new int[Q];
    String[] C = new String[Q];
    for (int i = 0; i < Q; i++) {
      T[i] = sc.nextInt();
      if (T[i] == 2) {
        F[i] = sc.nextInt();
        C[i] = sc.next();
      }
    }
    sc.close();

    StringBuilder pre = new StringBuilder();
    StringBuilder suf = new StringBuilder();
    boolean rev = false;
    for (int i = 0; i < Q; i++) {
      if (T[i] == 1) {
        rev = rev ? false : true;
      } else if (T[i] == 2) {
        if (F[i] == 1) {
          if (rev) {
            suf.append(C[i]);
          } else {
            pre.append(C[i]);
          }
        } else if (F[i] == 2) {
          if (rev) {
            pre.append(C[i]);
          } else {
            suf.append(C[i]);
          }
        }
      }
    }
    pre.reverse();

    StringBuilder ans = new StringBuilder(S);
    if (rev) {
      ans.reverse();
      StringBuilder tmp = pre;
      pre = suf;
      suf = tmp;
      pre.reverse();
      suf.reverse();
    }
    ans = new StringBuilder()
        .append(pre)
        .append(ans)
        .append(suf)
        ;

    System.out.println(ans);
  }
}
