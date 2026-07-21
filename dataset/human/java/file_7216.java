import java.util.Arrays;
import java.util.*;
public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
      int k = sc.nextInt();
      int n = sc.nextInt();
      int[] a = new int[n];
      int max = 0;
      for(int i=0;i<n;i++){
        a[i] = sc.nextInt();
      }
      for(int i=0;i<n;i++){
        if(i==0){
          max = a[1]-a[0];
        }else if(i==n-1){
          if(max<(k-a[i])+a[0]){
            max = (k-a[i])+a[0];
          }
        }else{
          if(max<a[i+1]-a[i]){
            max = a[i+1]-a[i];
          }
        }
      }
      int ans = k-max;
      System.out.println(ans);
    }
}
