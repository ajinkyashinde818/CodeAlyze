import java.util.*;
public class Main {
	   public static int gcd(int x,int y){
        if(x < y) return gcd(y, x);
        if(y == 0) return x;
        return gcd(y, x % y);
    }
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt(); 
      int count = 1;
      int ans = gcd(a,b);
      while(count<k){ans--;if(a%ans==0 &&b%ans==0){count++;}
                    }
	  System.out.println(ans);
  }
}
