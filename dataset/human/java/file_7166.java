import java.util.*;

public class Main {
  public static void main(String[] args) {
    try (Scanner sc = new Scanner(System.in)) {
      int K = sc.nextInt();
      int N = sc.nextInt();
      int[] arr = new int[N];
      for (int i = 0; i < N; i++) {
        arr[i] = sc.nextInt();
      }

      int[] distance = new int[N];// 次の家までの距離
      int ans = 0;
      for (int i = 0; i < N - 1; i++) {
        distance[i] = arr[i + 1] - arr[i];
        ans += distance[i];
      }
      distance[N - 1] = K - arr[N - 1] + arr[0];
      ans += distance[N - 1];

      java.util.Arrays.sort(distance);
      ans -= distance[N - 1];
      System.out.println(ans);
    }
  }
}
