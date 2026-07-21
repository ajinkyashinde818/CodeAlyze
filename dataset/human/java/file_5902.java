import java.util.*;

public class Main{
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    String s=sc.next();
    if (s.equals("abc")||
        s.equals("acb")||
        s.equals("bac")||
        s.equals("bca")||
        s.equals("cab")||
        s.equals("cba")) {
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
