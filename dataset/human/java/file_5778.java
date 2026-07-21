import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    String s = sc.next();

    String s1 = s.substring(0,1);
    String s2 = s.substring(1,2);
    String s3 = s.substring(2,3);

    if (s1.equals(s2) || s1.equals(s3) || s2.equals(s3)) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
    }

  }
}
