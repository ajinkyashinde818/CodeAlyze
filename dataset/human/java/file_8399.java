import java.util.*;
public class Main {
    public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
      
      //入力
      long A =sc.nextLong();
      long B =sc.nextLong();
      long too =0; //余り
      
      //計算用
      long a = A;
      long b = B;
      
      //ユークリッドの互除法利用
      //Aが大きいときの最大公約数を求める
      if(A>B){
        	while(b!=0){
        		too = (a%b);
        		a = b;
        		b =too;
        }
        //最小公倍数を求める(lcm=(A*B)/gcd)
       	System.out.println((A*B)/a); 
      }
      
      //Bが大きいときの最大公約数を求める
      else if(B>A){
          	while(a!=0){
      			too = (b%a);
      			b = a;
     			a =too;
          }
        //最小公倍数を求める
       	System.out.println((B*A)/b); 
      }
    }
}
