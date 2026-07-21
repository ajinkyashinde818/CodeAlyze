import java.util.Scanner;

class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
// splitで文字列を分ける。("")まで必要
//splitを使うために文字列型にする
    String[] N = sc.next().split("");
//０から数えて何個目にあるかを指定する
//文字列は＝＝じゃなく.equals()
      if (N[0].equals("9") || N[1].equals("9")){
      System.out.println("Yes") ;
      }
      else {
      System.out.println("No") ;
      }
  }
}
