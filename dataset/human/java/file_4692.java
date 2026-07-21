import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 整数の入力
        String N = sc.next();
        char[] W = new char[N.length()+1];
        W[0]='0';
        for(int i=0;i<N.length();i++){
            W[i+1] = N.charAt(i);
        }
        //System.out.println(sum2(W));
        //assert(sum2(W) == sum(W, W.length-1));
        System.out.println(sum2(W));
    }

    private static int sum2(char[] N){
        int dp0,dp1;
        dp0=0;
        dp1=1;
        for(int i=1;i<N.length;i++){
            int n0,n1;
            int c = N[i]-'0';
            n0 = Math.min(dp0 + c, dp1 + (10 - c));
            n1 = Math.min(dp1 + (10-c-1), dp0+c+1);
            dp0 = n0;
            dp1 = n1;
        }
        return dp0;
//        return Math.min(dp0, dp1);
    }
}
