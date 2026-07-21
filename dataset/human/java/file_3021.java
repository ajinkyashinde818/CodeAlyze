import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[] num = new int[n];
    for(int i = 0; i < m; i++) {
      int a = sc.nextInt() - 1;
      int b = sc.nextInt() - 1;
      if(a == 0) num[b]++;
      if(b == (n - 1)) num[a]++;
    }
    String ans = "IMPOSSIBLE";
    for(int i = 0; i < n; i++) {
      if(num[i] > 1) ans = "POSSIBLE";
    }
    System.out.println(ans);
  }
}
