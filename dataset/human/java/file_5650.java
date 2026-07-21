import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    int n = sc.nextInt();
    int k = sc.nextInt();
    long s = sc.nextLong();
    long nine = (long)(1e9);
    long[] arr = new long[n];
    int to = k-1;
    if(s!=nine) {
      for(int i = 0; i <= to; i++) {
        arr[i] = s;
      }
      for(int i = to+1; i < n; i++) {
        arr[i] = s+1;
      }
    } else {
      for(int i = 0; i < to; i++) {
        arr[i] = s;
      }
      long sub = s-(n-k);
      if(to>=0)arr[to] = sub;
      for(int i = to+1; i < n; i++) {
        arr[i] = 1;
      }
    }
    for(long l : arr) out.print(l + " ");
    out.println();
    out.close();
  }

}
