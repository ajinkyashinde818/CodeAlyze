import java.util.*;
import java.lang.Math;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String x = sc.next();
    String y = sc.next();
    int xn = (int)x.charAt(0);
    int yn = (int)y.charAt(0);
    
    if(xn == yn) System.out.println("=");
    else if(xn > yn) System.out.println(">");
    else System.out.println("<");
  }
}
