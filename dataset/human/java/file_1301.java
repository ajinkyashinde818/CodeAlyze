import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long[] a = new long[n];
      long sum = 0;
      for(int i = 0;i < n;i++){
        a[i]=sc.nextInt();
        sum += a[i];
      }
      long x = a[0];
      long min = Math.abs(sum-2*a[0]);
      for(int i = 1;i < n-1;i++){
        x += a[i];
        min = Math.min(min,Math.abs(sum-2*x));
      }
      System.out.println(min);
    }
}
