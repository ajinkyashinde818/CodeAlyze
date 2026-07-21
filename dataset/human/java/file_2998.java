import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    boolean[] toN = new boolean[N];
    boolean[] from1 = new boolean[N];
    for (int i = 0; i < M; i++) {
      int a = scanner.nextInt() - 1;
      int b = scanner.nextInt() - 1;
      if (a == 0) {
        from1[b] = true;
      }
      if (b == 0) {
        from1[a] = true;
      }
      if (a == N - 1) {
        toN[b] = true;
      }
      if (b == N - 1) {
        toN[a] = true;
      }
    }

    for (int i = 0; i < N; i++) {
      if (from1[i] && toN[i]) {
        System.out.println("POSSIBLE");
        return;
      }
    }
    System.out.println("IMPOSSIBLE");
  }
}
