import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long k = sc.nextLong();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    int count = 0;
    int x = 1;
    Set<Integer> set = new HashSet<>();
    int loopx = 1;
    while (true) {
      set.add(x);
      x = a[x-1];
      count++;
      if (set.contains(x)) {
        loopx = x;
        break;
      }
    }
    
    int loopCount = 0; 
    x = 1;
    while (true) {
      if (x == loopx) {
        break;
      }
      x = a[x-1];
      loopCount++;
    }
    int trueCount = count - loopCount;
    long trueK = k - loopCount;
    long amari = trueK % trueCount;

    x = 1;
    if ( k < loopCount) {
      for (int i = 0; i < k; i++) {
        x = a[x-1];
      }
    } else {
      for (int i = 0; i < loopCount + amari; i++) {
        x = a[x-1];
      }
    }

    System.out.println(x);

  }
}
