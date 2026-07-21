import java.util.*;
public class Main{
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] a = new int[n];
      int[] b = new int[n];
      int[] c = new int[n-1];
      int sum = 0;
      for(int i = 0;i < n;i++)a[i]=sc.nextInt();
      for(int i = 0;i < n;i++)b[i]=sc.nextInt();
      for(int i = 0;i < n-1;i++)c[i]=sc.nextInt();
      for(int i = 0;i < n;i++){
      	int x = a[i];
        sum += b[x-1];
      }
      for(int i = 0;i < n-1;i++){
      	if(a[i+1]-a[i]==1)sum += c[a[i]-1];
      }
      System.out.println(sum);
    }
    public static int lcm(int x, int y){
      return x*y/gcd(x,y);
    }
    public static int gcd(int x, int y){
      if(x < y)return gcd(y,x);
      if(y==0)return x;
      return gcd(y,x%y);
    }
}
