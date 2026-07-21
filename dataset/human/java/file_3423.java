import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String ans = "No";
    int p = 0;
    if((n % 10) == 9) p++;
    n /= 10;
    if((n % 10) == 9) p++;
    if(p > 0) ans = "Yes";
    System.out.println(ans);
  }
}
