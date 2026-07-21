import java.util.*;
// 繰り返し回数N
// 一行目数値1　数値2 
// 二行目数値1　数値2 で渡された場合で渡された場合
public class Main {
  public static void main(String[] args ) throws Exception {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String ansFlg = "";
    String ans = "";
    int stack = 0;
    String stackFlg = "";
    for (int i = 0; i < N; i++) {
      String token1 = sc.next();
      String token2 = sc.next();
      // 文字列比較は == ではなく　StringA.equals(StringB)
      if(token1.equals(token2)){
          stack += 1;
          stackFlg = "X";
          if(stack == 3){
              ansFlg = "X";
              break;
          }else{
              //特になし
          }
      }
      // stackFlgがない場合にstackをリセットし、その後スタックフラグを切る
      if(stackFlg.equals("X")){
          //特になし
      }else{
          stack = 0;
      }
      stackFlg = "";
    }
    
    if(ansFlg == "X"){
        ans = "Yes";
    }else{
        ans = "No";
    }
    System.out.println(ans);
  }
}
