import java.io.*;
import java.util.Scanner;

public class Main {
  
  public static void main(String[] args){
    
    try {
      //ローカル変数定義
      int internal_rating;      //内部レーティング
      int display_rating;       //表示レーティング
      int participation_times;  //参加回数
      
      //標準入力受け取り
      Scanner scan = new Scanner(System.in);
      String  N    = scan.next();
      String  R    = scan.next();
      
      participation_times = Integer.parseInt(N);
      display_rating      = Integer.parseInt(R);
      
      //内部レーティング算出
      if (participation_times >= 10) {
        internal_rating = display_rating;
      } else {
        internal_rating = display_rating + 100*(10-participation_times);
      }
      
      System.out.println(internal_rating);
      
    } catch (Exception e) {
      
      System.out.println("error");

    }
  }
}
