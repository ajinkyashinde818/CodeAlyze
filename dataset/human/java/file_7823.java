import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long K = sc.nextLong();
    int[] A = new int[N];
    for (int i = 0; i < N; i++)
      A[i] = sc.nextInt();
    sc.close();

    int[] n = new int[N];
    Arrays.fill(n,  -1);

    int cnt = 1;
    n[0] = cnt;
    int next = A[0] - 1;
    while (n[next] < 0) {
      n[next] = ++cnt;
      next = A[next] - 1;
    }

    int begin = n[next] - 1;
    int loop = cnt - begin;
    long mod = (K < begin) ? (K - begin) : ((K - begin) % loop);

    int ans = 1;
    for (int i = 0; i < begin + mod; i++)
      ans = A[ans - 1];
    System.out.println(ans);
  }
}
