import java.util.*;
import java.math.*;

public class Main {
    static final int MOD = 1_000_000_007; // 10^9+7
    // static final int MAX = 2_147_483_646; // intの最大値
    static final int INF = 1_000_000_000; // 10^9
    static final int MAX = 10_000_000;
    static long[] fact = new long[100];
    static int[] coin;
    static int[][] a;
    static int n,m,x;
    static int print = INF;
        public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
         n = sc.nextInt();
         m = sc.nextInt();
         x = sc.nextInt();
        coin = new int[n];
        a = new int[n][m];
        for(int i = 0;i < n;i++){
            coin[i] = sc.nextInt();
            for(int j = 0;j < m;j++){
                a[i][j] = sc.nextInt();
            }
        }
        int[] ary = new int[m];
        dfs(0,ary,0);
        if(print == INF)print = -1;
        System.out.println(print);
    }
    static void dfs(int i,int[] ary,int ans){
        //x超えてるかチェック
        boolean poyo = true;
        for(int s = 0;s < m;s++){
            if(ary[s] < x)poyo = false;
        }
        if(poyo){
            if(print > ans)print = ans;
            return;
        }
        if(i==n)return;
        dfs(i+1,ary,ans);
        int[] tmp = new int[m];
        for(int s = 0;s < m;s++){
            tmp[s] = ary[s]+a[i][s];
        }
        ans+=coin[i];
        dfs(i+1,tmp,ans);
    }
    
}
