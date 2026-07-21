import java.util.Scanner;
public class Main {
  public static void main(String[] arga) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    int S = sub(s);
    int T = sub(t);
    if(S > T) {
      System.out.println(">");
    }else if(S < T) {
      System.out.println("<");
    }else {
      System.out.println("=");
    }
  }
  static int sub(String s) {
    if(s.equals("A")) return 1;
    else if(s.equals("B")) return 2;
    else if(s.equals("C")) return 3;
    else if(s.equals("D")) return 4;
    else if(s.equals("E")) return 5;
    else if(s.equals("F")) return 6;
    else return 0;
  }
}
