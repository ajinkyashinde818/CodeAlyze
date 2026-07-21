import java.util.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);
    
    int N = sc.nextInt();
    int[] a = new int[N];

    long sum = 0;

    for (int i = 0; i < N; i++) {
      a[i] = sc.nextInt();
      sum += a[i];
    }

    sc.close();
    
    long min = Math.abs(sum - (2 * a[0]));
    long x = a[0];

    for (int i = 1; i < N-1; i++) {
      x += a[i];
      min = Math.min(min, Math.abs(sum - (2 * x)));
    }

    System.out.println(min);

  }

}
