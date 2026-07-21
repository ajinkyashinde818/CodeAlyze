import java.util.*;
public class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String s = Integer.toString(n);
    if(s.charAt(0)=='9' || s.charAt(1)=='9'){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
