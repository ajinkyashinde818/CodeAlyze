import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] a = new int[M];
    int[] b = new int[M];
    for (int i = 0; i < M; i++) {
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
    }
    boolean[] path1 = new boolean[N + 1]; // 1->midに行けるかどうか
    boolean[] path2 = new boolean[N + 1]; // mid->Nに行けるかどうか
    Arrays.fill(path1, false);
    Arrays.fill(path2, false);
    for (int i = 0; i < M; i++) {
      if (a[i] == 1) {
        path1[b[i]] = true;
      }
      if (b[i] == N) {
        path2[a[i]] = true;
      }
    }
    for (int i = 1; i <= N; i++) {
      if (path1[i] && path2[i]) {
        System.out.println("POSSIBLE");
        return;
      }
    }
    System.out.println("IMPOSSIBLE");
  }
}
