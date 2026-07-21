import java.util.*;
import java.math.*;
public class Main {
    static final int MOD = 1_000_000_007; // 10^9+7
    //static final int MAX = 2_147_483_646; // intの最大値
    static final int INF = 1_000_000_000; // 10^9
    static final int MAX = 10_000_000;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] a = new char[n][n];
        char[][] b = new char[m][m];
        for(int i = 0;i < n;i++){
            a[i] = sc.next().toCharArray();
        }
        for(int i = 0;i < m;i++){
            b[i] = sc.next().toCharArray();
        }
        for(int i = 0;i <= n-m;i++){
            for(int j = 0;j <= n-m;j++){
                //i,j成分が一致するときに全探索する
                if(a[i][j] == b[0][0]){
                    boolean poyo = false;
                    for(int s = 0;s < m;s++){
                        for(int t = 0;t < m;t++){
                            if(a[i+s][j+t]!=b[s][t]){
                                poyo = true;
                                break;
                            }
                        }
                        if(poyo)break;
                    }
                    if(!poyo){
                        System.out.println("Yes");
                        return;
                    }
                }
            }
        }
        System.out.println("No");

    }       
}
