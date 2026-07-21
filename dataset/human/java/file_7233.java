import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int k = in.nextInt();
    int n = in.nextInt();
    int[] a = new int[n];
    int maxDist = Integer.MIN_VALUE;
    a[0] = in.nextInt();
    for (int i = 1; i < n; ++i) {
      a[i] = in.nextInt();
      int maxDist1 = a[i] - a[i - 1];
      if (maxDist1 > maxDist) {
        maxDist = maxDist1;
      }
    }
    if (k - a[n - 1] + a[0] > maxDist) {
      maxDist = k - a[n - 1] + a[0];
    }
    System.out.println(k - maxDist);
  }
}
