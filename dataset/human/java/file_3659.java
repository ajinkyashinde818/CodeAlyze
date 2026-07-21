import java.util.*;

public class Main{
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    String x=sc.next();
    String y=sc.next();
    int x1=(int)x.charAt(0);
    int y1=(int)y.charAt(0);
    // System.out.println(x1+" "+y1);
    if(x1>y1) System.out.println(">");
    if(x1==y1) System.out.println("=");
    if(x1<y1) System.out.println("<");
  }
}
