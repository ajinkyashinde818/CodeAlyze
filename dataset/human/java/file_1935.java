import java.util.*;

public class Main {
    static int[] array;
    static int n;
    static int g;
    static int[] p;
    static int[] c;
    static int INF = 1001001009;
    static int ans = INF;
    
    public static void main(String[] args) throws Exception {
        // Your code here! 
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        g = sc.nextInt() / 100;
        
        // array: 長さnのbit列
        array = new int[n];
        
        // 全探索する時のデータを取得
        p = new int[n];
        c = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt() / 100;
        }
        
        // arrayのパターンを全探索
        // ex.[1, 1, 1], [1, 1, 2], ... , [m, m, m]
        dfs(0, 0);
        
        // ans: costの最小値
        if (ans == INF) ans = -1;
        System.out.println(ans);
    }
    
    public static void dfs(int index, int now) {
        // 終了条件
        if (index == n) {
            // できあがったarrayで計算
            int score = 0;
            int cost = 0;
            
            for (int i = 0; i < n; i++) {
                if (array[i] == 1) {
                    score += (i+1) * p[i] + c[i];
                    cost += p[i];
                }
            }
            
            
            if (score < g) {
                for (int i = n-1; i >= 0; i--) {
                    if (array[i] == 0) {
                        int goal = g - score;
                        int max = (i+1) * (p[i]-1);
            
                        
                        if (goal <= max) {
                            int need = (goal+i) / (i+1);
                            score = g;
                            cost += need;
                        }
                        
                        break;
                    }
                }
            }
            
            if (score >= g) {
                ans = Math.min(ans, cost);
            }
            return;
        }
        
        // 次項の取る値: 0 or 1
        for (int i = 0; i < 2; i++) {
            array[index] = i;
            dfs(index + 1, i);
        }
    }
}
