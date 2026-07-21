import java.util.*;
import java.math.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int n = sc.nextInt();
    int count = 0;
    StringBuffer pre = new StringBuffer();
    StringBuffer tail = new StringBuffer();
    for(int i = 0; i < n; ++i) {
      int op = sc.nextInt();
      if(op == 1) {
        ++count;
      }
      if(op == 2) {
        int mid = sc.nextInt();
        if((mid == 1) && (count & 1) == 0 || (mid == 2 && (count & 1) == 1)) {
          pre.append(sc.next().charAt(0) + "");
        } else {
          tail.append(sc.next().charAt(0) + "");
        }
      }
    }
    s = ope1(pre.toString()) + s + tail.toString();
    if((count & 1) == 1) s = ope1(s);
    System.out.println(s);
  }
  
  private static String ope1(String s) {
    StringBuffer str = new StringBuffer();
    char[] a = s.toCharArray();
    for(int i = a.length - 1; i > -1; --i) {
      str.append(a[i] + "");
    }
    return str.toString();
  }
}
