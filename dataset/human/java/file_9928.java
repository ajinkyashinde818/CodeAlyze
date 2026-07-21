import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
    static final int MOD = 1000000007;
    static final int INF = 1 << 30;
    static final int ALF = 26;

    Main() {
        Scanner sc = new Scanner(System.in);
        long ans = 0;
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int[] C = new int[N];
        int[][] A = new int[N][M];
        for (int i = 0; i < N; i++) {
            C[i] = sc.nextInt();
            for (int j = 0; j < M; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        int min = INF;
        for (int bit = 1; bit < 1 << N; bit++) {
            int[] sum = new int[M];
            int val = 0;
            for (int k = 0; k < N; k++) {
                int mask = 1 << k;
                boolean buy = (mask & bit)!=0;
                if(buy) {
                    val += C[k];
                    for (int i = 0; i < M; i++) {
                        sum[i] += A[k][i];
                    }
                }
            }
            boolean ok = true;
            for (int i = 0; i < M; i++) {
                if(sum[i]<X)ok=false;
            }
            if(ok){
                if(min>val){
                    min = val;
                }
            }
        }

        System.out.println(min==INF?-1:min);
    }

    public static void main(String[] args) {
        new Main();
    }
}
