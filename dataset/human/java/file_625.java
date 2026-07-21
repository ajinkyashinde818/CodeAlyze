import java.io.*;
import java.util.Scanner;

public class Main {
  
  public static void main(String[] args){
    
    try {
      //ローカル変数定義
      //標準入力受け取り
      Scanner scan = new Scanner(System.in);
      int N = Integer.parseInt(scan.next());
      int R = Integer.parseInt(scan.next());

      //内部レーティング算出
      if ( N <= 10) {
		R = R + ( 100 * (10 - N));
      }
      System.out.println(R);
      
    } catch (Exception e) {
      
      System.out.println("error");

    }
  }
}
