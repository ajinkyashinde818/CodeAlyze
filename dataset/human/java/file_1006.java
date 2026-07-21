import java.util.*;
 
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    long C = sc.nextLong();
    long[] x = new long[N];
    long[] v = new long[N];
    long ans = 0;
    
    for(int i=0; i<N; i++){
      x[i] = sc.nextLong();
      v[i] = sc.nextLong();
    }
    
    long sum1 = 0;
    long sum2 = 0;
    long[] a = new long[N+1];
    long[] b = new long[N+1];
    
    for(int i=0; i<N; i++){
      sum1 += v[i];
      a[i+1] =  sum1 - x[i];
      a[i+1] = Math.max(a[i], a[i+1]);
      sum2 += v[N-i-1];
      b[i+1] = sum2 - (C - x[N-i-1]);
      b[i+1] = Math.max(b[i], b[i+1]);
    }
    
    for(int i=0; i<N; i++){
      long t1 = Math.max(a[i+1], a[i+1] - x[i] + b[N-i-1]);
      long t2 = Math.max(b[i+1], b[i+1] - (C-x[N-i-1]) + a[N-i-1]);
      long t3 = Math.max(t1, t2);
      ans = Math.max(ans, t3);
    }
    System.out.println(ans);
  }
}
