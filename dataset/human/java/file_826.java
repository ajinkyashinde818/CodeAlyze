import java.util.*;
 public class Main {
	public static void main(String[] args){
      Scanner sc = new Scanner(System.in);

      int N = sc.nextInt();
      int R = sc.nextInt();
      int A = 0;
       
      if(N < 10){
       A = 100 * (10 - N);
      }


      System.out.print(A + R);
   }
 }
