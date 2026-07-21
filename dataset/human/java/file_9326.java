import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws Exception {
    try (final var stdin = new InputStreamReader(System.in);
         final var br = new BufferedReader(stdin)) {
      final var n = Integer.parseInt(br.readLine());
      final var a = new boolean[n];
      for (int i = 0; i < n; i++) {
        final var line = br.readLine().split(" ");
        a[i] = Integer.parseInt(line[0]) == Integer.parseInt(line[1]);
      }

      for (int i = 3; i <= n; i++) {
        if (a[i - 3] && a[i - 2] && a[i - 1]) {
          System.out.println("Yes");
          return;
        }
      }

      System.out.println("No");
    }
  }
}
