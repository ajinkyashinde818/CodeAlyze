import java.util.*;
public class Main{   
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      int[] a = new int[m];
      int[] b = new int[m];
      HashSet<Integer> set1 = new HashSet<>();
      HashSet<Integer> set2 = new HashSet<>();
      for(int i = 0;i < m;i++){
      	a[i]=sc.nextInt();
        b[i]=sc.nextInt();
        if(a[i]==1)set1.add(b[i]);
        if(b[i]==n)set2.add(a[i]);
      }
      set1.retainAll(set2);
      if(set1.size()>0)System.out.println("POSSIBLE");
      else
      System.out.println("IMPOSSIBLE");
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
