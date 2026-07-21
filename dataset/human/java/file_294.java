import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.next());
    long a[] = new long[n];
    int flg = 0;
    long sum = 0;
    long max = 0;
    long min = Long.MAX_VALUE;
    int cnt = 0;

    for (int i=0; i<n; i++) {
      a[i] = Integer.parseInt(sc.next());
      if (a[i] < 0) {
        a[i] = -1 * a[i];
        cnt++;
      }
      if (a[i] < min) {
        min = a[i];
      }
      sum += a[i];
    }
    
    if (cnt%2 == 1) {
	  sum -= 2*min;
    }
    
    System.out.println(sum);
  }
}
