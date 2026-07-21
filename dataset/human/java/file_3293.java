import java.util.*;

public class Main{
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    String n=sc.next();
    if (n.charAt(0)=='9'||n.charAt(1)=='9') {
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
