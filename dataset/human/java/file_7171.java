import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    long k = sc.nextLong();
    int n = sc.nextInt();
    long[] a = new long[n];

    for(int i = 0; i < n; i++){
      a[i] = sc.nextLong(); 
    }

    Arrays.sort(a);
    long d = k + a[0] - a[n - 1];
    
    for(int i = 1; i < n; i++){
      if(d < a[i] - a[i - 1]){
        d = a[i] - a[i - 1];
      }
    }

    System.out.println(k - d);
  }
}
