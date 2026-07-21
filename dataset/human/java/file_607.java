import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int R = sc.nextInt();
    sc.close();

    int ans = R;
    if (N < 10) {
      ans += 100 * (10 - N);
    }
    System.out.println(ans);
  }
}
