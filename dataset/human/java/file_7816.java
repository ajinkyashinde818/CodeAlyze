import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long k = sc.nextLong();
    int[] direct = new int[n + 1];
    int[] visitCounts = new int[n + 1];
    Arrays.fill(direct, -1);
    Arrays.fill(visitCounts, 0);

    for (int i = 1; i <= n; i++) {
      direct[i] = sc.nextInt();
    }

    int counter = 0;
    int next = 1;
    int cycle = 0;
    int step = 0;
    while (true) {
      counter++;
      if (visitCounts[next] > 0) {
        cycle = counter - visitCounts[next];
        step = visitCounts[next] - 1;
        break;
      }
      visitCounts[next] = counter;
      next = direct[next];
    }
    if (k > (long) step) {
      k -= (long)step;
      k %= (long)cycle;
    } else {
      next = 1;
    }
    for(long count = 0; count < k; count++){
      next = direct[next];
    }
    System.out.println(next);
  }
}
