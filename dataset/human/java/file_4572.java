import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int ans = 0;
    if (C <= A + B + 1) {
      ans = B + C;
    } else {
      ans = B + (A + B + 1);
    }
    System.out.println(ans);
  }
}
