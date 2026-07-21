import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws Exception{
        BufferedReader stdR = new BufferedReader(new InputStreamReader(System.in));
        String s = stdR.readLine();
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for(int i = 0 ; i < s.length(); i++) {
            if(dp[i] == true) {
                if(i + 7 <= s.length() && s.substring(i, i + 7).equals("dreamer")) {
                    dp[i + 7] = true;
                }
                if(i + 6 <= s.length() && s.substring(i, i + 6).equals("eraser")) {
                    dp[i + 6] = true;
                }
                if(i + 5 <= s.length() && (s.substring(i, i + 5).equals("dream") || s.substring(i, i + 5).equals("erase"))) {
                    dp[i + 5] = true;
                }
            }
        }
        if(dp[s.length()]) {
            System.out.println("YES");
        }else {
            System.out.println("NO");
        }
    }
}
