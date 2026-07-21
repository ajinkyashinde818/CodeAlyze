import java.util.*;
 
public class Main {
	public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      long A =sc.nextLong();
	  long B =sc.nextLong();
      
      long a = A;
      long b = B;
      long o = 0;
      
      if(A>B){
      while(b !=0){
      o = a%b;
      //次にb%oにしたいからa%bを更新していく
      //最後に余りが出なくなるまで割っていけばそれが最大公約数となる
      a = b;
      b = o;
      }
        //aはbに代入されて更新された状態であるため、aは実際割る側の数となっている
        //最小公倍数=入力された数(A*B)/最大公約数を出したさに最後に割った数(bの位置)
      System.out.println(A*B/a);   
      }
      
   if(B>A){
      while(a !=0){
       o = b%a;
        b = a;
        a = o;
      }
     System.out.print(A*B/b);
   }
  }
}
