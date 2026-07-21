import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int K = scanner.nextInt();
    int S = scanner.nextInt();
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < K; i++) sb.append(S).append(' ');
    int T = S == 1_000_000_000 ? 1 : 1_000_000_000;
    for (int i = K; i < N; i++) sb.append(T).append(' ');
    sb.setLength(sb.length() - 1);
    System.out.println(sb.toString());
  }
}
