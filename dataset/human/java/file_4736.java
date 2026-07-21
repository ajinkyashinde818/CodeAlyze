import java.util.*;
import java.math.*;
import java.io.BufferedInputStream;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner (new BufferedInputStream(System.in));
    String s = sc.next();
    int n = s.length();
    int[][] dp = new int[n][2];
    dp[0][0] = s.charAt(n - 1) - '0';
    int plus = 0;
    if(dp[0][0] == 0) {
      dp[0][1] = 0;
    } else {
      dp[0][1] = 10 - dp[0][0];
      plus = 1;
    }
    for(int i = 1; i < n; ++i) {
      int now = s.charAt(n - 1 - i) - '0';
      dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1] + 1) + now;
      if(now == 0) {
        dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1] + plus);
        plus = 0;
      } else {
        dp[i][1] = Math.min(dp[i - 1][0] + 10 - now, dp[i - 1][1] + 10 - now - plus);
        plus = 1;
      }
    }        
    System.out.println(Math.min(dp[n - 1][0], dp[n - 1][1] + 1));
  }
}
