import java.util.*;

public class Main {
	
	public static void main(String[] args) {

		// argumentの取得
		Scanner s = new Scanner(System.in);

		int A = s.nextInt();
        int B = s.nextInt();
      
        if (A < B) {
          int tmp = A;
          A = B;
          B = tmp;
        }
      
        if (B == 1) {
          System.out.println(A);
          return;
        }
      
        // なぜ long X = A * B; だとだめなのだ。。
        long X = A;
        X = X * B;
      
        //System.out.println("A = " + A); //debug
        //System.out.println("B = " + B); //debug
        //System.out.println("X = " + X); //debug
      
        int R = A % B; // 割った余りが入る	
        //System.out.println("R = " + R); //debug
      
        if (R == 0) {
          System.out.println(A);
          return;
        }
      
        // 無限Loop
      while(true){
          A = B;
          //System.out.println("A = " + A); //debug
          B = R;
          //System.out.println("B = " + B); //debug
          R = A % B;  // 再度割った余りが入る
          
          //System.out.println("R = " + R); //debug
        
          if(R == 0){
            break;
          }
      }
      
      System.out.println(X/B);
	} 
}
