import java.util.*;
import java.math.*;

class Main {
  public static void main(String[] args) {
    Scanner stdIn = new Scanner(System.in);
    int n = stdIn.nextInt();
    long[] a = new long[n];
    long[] b = new long[2*n];
    int un = 0;
    for(int i = 0;i<n;i++) {
      a[i] = stdIn.nextInt();
      if(a[i]<0) {
      un+=1;
      a[i] = Math.abs(a[i]);
    }
    }
    long min = a[0];
    long k = 0;
    if(un%2==0)  k = addArray(a);
    if(un%2==1) {
      for(int i = 0;i<a.length;i++) {
      if(min>a[i]) min = a[i];
    }
    k = addArray(a);
    k = k - 2*min;
    }
    System.out.println(k);
  }
  static long addArray(long[] a) {
    long count = 0;
    for(int i = 0;i<a.length;i++) {
      count += a[i];
    }
    return count;
  }
}
