import java.util.*;
public class Main{   
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int k = sc.nextInt();
      int s = sc.nextInt();
      int[] a = new int[n];
      int inf = 1000000000;
      Arrays.fill(a,inf);
      if(s<inf){
        for(int i=0;i<k;i++)a[i]=s;
      }else{
        for(int i=0;i<n-k;i++)a[i]--;
      }
      System.out.print(a[0]);
      for(int i=1;i<n;i++)System.out.print(" "+a[i]);
      System.out.println("");
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
class Pair{
    int a,b;

    Pair(int a, int b){
      this.a = a;
      this.b = b;
    }
}
