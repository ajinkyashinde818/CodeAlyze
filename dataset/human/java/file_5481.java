import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    String ans = "ABC";
    if(x >= 1200) ans = "ARC";
    System.out.println(ans);
  }
}
