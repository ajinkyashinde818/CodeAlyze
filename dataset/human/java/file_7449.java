import java.util.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    StringBuilder SS = new StringBuilder(S);
    int N = SS.length(), check =0;
    SS = SS.reverse();    
    while (true) {
      if (N >= 5) {
        if (SS.substring(0,5).equals("esare") || SS.substring(0,5).equals("maerd")) {
          SS = SS.delete(0,5);
          N = SS.length();
          continue;
        }
      }
      if (N >= 6) {
        if (SS.substring(0,6).equals("resare")) {
          SS = SS.delete(0,6);
          N = SS.length();
          continue;
        }
      }
      if (N >= 7) { 
        if (SS.substring(0,7).equals("remaerd")) {
          SS = SS.delete(0,7);
          N = SS.length();
          continue;
        }
      }
      break;
    }
    if (N == 0) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  } 
}
