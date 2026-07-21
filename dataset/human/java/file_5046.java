import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int p = 0;
    StringBuilder sb1 = new StringBuilder();
    StringBuilder sb2 = new StringBuilder();    
    int q = sc.nextInt();
    for(int i = 0; i < q; i++) {
      int f = sc.nextInt();
      if(f == 1) {
        p = 1 - p;
      } else {
        int t = sc.nextInt();
        String c = sc.next();
        if(p == 0) {
          if(t == 1) {
            sb1.append(c);
          } else {
            sb2.append(c);
          }
        } else {
          if(t == 1) {
            sb2.append(c);
          } else {
            sb1.append(c);
          }          
        }
      }
    }
    String s1 = new String(sb1);
    String s2 = new String(sb2);
    StringBuffer ss = new StringBuffer(s1);
    String ans = ss.reverse().toString() + s + s2;
    if(p == 1) {
      StringBuffer str = new StringBuffer(ans);
      ans = str.reverse().toString();
    }
    System.out.println(ans);
  }
}
