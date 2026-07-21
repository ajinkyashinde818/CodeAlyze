import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] t = new String[]{"dream", "dreamer", "erase", "eraser"};
        
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        
        for(int i = 1; i < dp.length; i++) {
            if(!dp[i - 1]) continue;
            for(int j = 0; j < t.length; j++) {
                if(i - 1 + t[j].length() <= s.length()
                    && s.substring(i-1, i - 1 + t[j].length()).equals(t[j]))
                    dp[i + t[j].length() - 1] = true;
            }
        }
        
        System.out.println(dp[dp.length - 1] ? "YES" : "NO");
    }
}
