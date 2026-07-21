import java.util.*;
import static java.lang.System.*;

class Main {
  public static final int MOD = 1000000007;
  public static final int INF = 1000000000;
  public static void main(String[] args) {
    Scanner sc = new Scanner(in);
    int N = sc.nextInt();
    int A[] = new int[N];
    long sum[] = new long[N+1];
    sum[0] = 0;
    for(int i=0; i<N; i++){
      A[i] = sc.nextInt();
      sum[i+1] = sum[i] + A[i];
    }
    long ans = 1000000000000L;
    for(int i=1; i<N; i++){
      ans = Math.min(ans, Math.abs(sum[N] - sum[i] - sum[i]) );
    }
    out.println(ans);
  }

  public static int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
  }
}
