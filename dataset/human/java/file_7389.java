import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String[] words = new String[]{"dream","dreamer","erase","eraser"};
    int n = s.length();
    boolean[] dp = new boolean[n+1];
    dp[n] = true;
    for (int i = n-1; i >= 0; i--){
      for (String word: words){
        if (s.substring(i).startsWith(word)){
          dp[i] = dp[i] || dp[i+word.length()];
        }
      }
    }
    if (dp[0] == true){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}
