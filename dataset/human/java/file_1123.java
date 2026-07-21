import java.util.*;
public class Main{

  public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long[] arr = new long[n];

      for(int i = 0; i < n; i++) {
        arr[i] = sc.nextLong();
      }
      
      long[] leftSum = new long[n];
      for(int i = 0; i < n - 1; i++) {
        if(i == 0) {
          leftSum[i] = arr[i];
        } else {
          leftSum[i] = arr[i] + leftSum[i - 1];
        }
      }

      long[] rightSum = new long[n];
      for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1) {
          rightSum[i] = arr[i];
        } else {
          rightSum[i] = arr[i] + rightSum[i + 1];
        }
      }
      long min = Long.MAX_VALUE;
      for(int i = 0; i < n - 1; i++) {
        min = Math.min(min, Math.abs(leftSum[i] - rightSum[i+1]));
      }
      System.out.println(min);
  }
}
