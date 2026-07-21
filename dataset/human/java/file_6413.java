import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int K = scanner.nextInt();
    int S = scanner.nextInt();
    int total = 0;
    for (int X = 0; X <= K; X++) {
      total += Math.max(Math.min(K, S - X) - Math.max(S - K - X, 0) + 1, 0);
    }
    System.out.println(total);
  }
}
