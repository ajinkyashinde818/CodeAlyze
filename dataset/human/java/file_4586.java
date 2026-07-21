import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    
    int ans = 0;
    int d = Math.min(B, C);
    B -= d;
    C -= d;
    ans += 2*d;
    
    int e = Math.min(C, A);
    C -= e;
    A -= e;
    ans += e;
    ans += B;
    if (C > 0) {
      ans++;
    }
    
    System.out.println(ans);
  }
}
