import java.util.*;

public class Main{
	public static void main(String[] arg){
    	Scanner sc=new Scanner(System.in);
      int k=sc.nextInt();
      int n=sc.nextInt();
      int a[]=new int[n];
      for(int i=0;i<n;i++){
          a[i]=sc.nextInt();
          if(a[i]>=k){
              a[i]-=k;
          }
          
      }
      int max=Integer.MIN_VALUE;
      for(int i=1;i<n;i++){
          max=Math.max(max,Math.abs(a[i]-a[i-1]));
      }
      int m=k-a[n-1] + a[0];
      System.out.println(k-Math.max(max,m));
        
    }
}
