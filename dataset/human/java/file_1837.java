import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int d = scanner.nextInt();
    int g = scanner.nextInt();
    int[] p = new int[d + 1];
    int[] c = new int[d + 1];
    for (int i = 1; i <= d; i++) {
      p[i] = scanner.nextInt();
      c[i] = scanner.nextInt();
    }

    int[][] m = new int[d + 1][1001];
    for (int i = 1; i <= d; i++) {
      for (int j = 1; j <= 1000; j++) {
        for (int k = 0; k <= p[i] && k <= j; k++) {
          int score = i * k * 100;
          if (k == p[i]) score += c[i];
          score += m[i - 1][j - k];
          if (score > m[i][j]) m[i][j] = score;
        }
      }
    }

    for (int i = 1; i <= 1000; i++) {
      if (m[d][i] >= g) {
        System.out.println(i);
        return;
      }
    }
  }
}
