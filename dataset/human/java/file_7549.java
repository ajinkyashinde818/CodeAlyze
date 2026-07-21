import java.util.*;

class Main{
    static boolean dp[] = new boolean[(int)1e5+10];
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        char[] s = in.next().toCharArray();
        dp[0] = true;
        for(int i = 0 ; i < s.length; i++){
            if(!dp[i])continue;
            if(i+5<=s.length&&s[i]=='d'&&s[i+1]=='r'&&s[i+2]=='e'&&s[i+3]=='a'&&s[i+4]=='m')
                dp[i+5] = true;
            if(i+7<=s.length&&s[i]=='d'&&s[i+1]=='r'&&s[i+2]=='e'&&s[i+3]=='a'&&s[i+4]=='m'&&s[i+5]=='e'&&s[i+6]=='r')
                dp[i+7] = true;
            if(i+5<=s.length&&s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e')
                dp[i+5] = true;
            if(i+6<=s.length&&s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e'&&s[i+5]=='r')
                dp[i+6] = true;
        }

        if(dp[s.length])
            System.out.println("YES");
        else System.out.println("NO");
    }
}
