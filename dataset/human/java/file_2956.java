import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt();
    int M = scn.nextInt();

    boolean[] exists1toi = new boolean[N + 1];
    Arrays.fill(exists1toi, false);
    boolean[] existsitoN = new boolean[N + 1];
    Arrays.fill(existsitoN, false);

    for (int i = 0; i < M; i++) {
      int a = scn.nextInt();
      int b = scn.nextInt();

      if (a == 1) {
        exists1toi[b] = true;
      }
      if (b == 1) {
        exists1toi[a] = true;
      }
      if (a == N) {
        existsitoN[b] = true;
      }
      if (b == N) {
        existsitoN[a] = true;
      }
    }

    boolean ans = false;
    for (int i = 1; i <= N; i++) {
      if (exists1toi[i] && existsitoN[i]) {
        ans = true;
      }

    }

    if (ans) {
      System.out.println("POSSIBLE");
    } else {
      System.out.println("IMPOSSIBLE");
    }

  }
}
