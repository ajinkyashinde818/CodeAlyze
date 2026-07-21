import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long[] arr = new long[n];
      int negCnt = 0;
      long sum = 0;
      long min = Long.MAX_VALUE;
      for(int i = 0; i < n; i++) {
        long num = sc.nextLong();
        if(num < 0) negCnt++;
        arr[i] = Math.abs(num);
        sum += arr[i];
        min = Math.min(min, arr[i]);
      }
      if(negCnt % 2 == 1) {
        sum -= min*2;
      }
      System.out.println(sum);
  }
}
