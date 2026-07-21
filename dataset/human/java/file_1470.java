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

    Main() {
        Scanner sc = new Scanner(System.in);
        long ans = 0;
        int N = sc.nextInt();
        int M = sc.nextInt();
        char[][] a = new char[N][];
        char[][] b = new char[M][];
        for (int i = 0; i < N; i++) {
            a[i] = sc.next().toCharArray();
        }
        for (int i = 0; i < M; i++) {
            b[i] = sc.next().toCharArray();
        }
        for (int sy = 0; sy <= N - M; sy++) {
            for (int sx = 0; sx <= N - M; sx++) {
                boolean ok = true;
                for (int y = 0; y < M; y++) {
                    for (int x = 0; x < M; x++) {
                        if(a[sy+y][sx+x]!=b[y][x]){
                            ok = false;
                        }
                    }
                }
                if(ok){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }

    public static void main(String[] args) {
        new Main();
    }
}
