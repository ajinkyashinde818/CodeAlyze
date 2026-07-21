import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[] a = new long[n+1];
    long[] b = new long[n+1];
    int cnt = 0;
    long min = 1000000000;
    for(int i = 1;i <= n;i++){
      a[i]=sc.nextLong();
      if(a[i]<0){
        cnt++;
      }
      b[i]=Math.abs(a[i]);
      min = Math.min(min,b[i]);
    }
    long sum = 0;
    for(int i = 1;i <= n;i++)sum+=b[i];
    if(cnt%2==0){
      System.out.println(sum);
    }else{
      sum -= min*2;
      System.out.println(sum);
    }
  }
}
