import java.util.Scanner;

public class Main {  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] a = new long[N];
    long total =0;
    for (int i =0; i<N; i++) {
      a[i] = sc.nextLong();
      total += a[i];
    }
    long x =0 ,y = total, min = Math.abs(total - a[0] * 2);
    for (int i =0; i<N-1; i++) {
      x += a[i];
      y = total - x;
      min = Math.min(Math.abs(x-y),min);
    }
    System.out.print(min);
  }
}
