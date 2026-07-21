import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner sc = new Scanner(is);
        int N = sc.nextInt();
        long K = sc.nextLong();

        int A[] = new int[N];
        boolean pass[] = new boolean[N];
        int th[] = new int[N];

        for (int i = 0 ; i < N; i++)
            A[i] = sc.nextInt()-1;

        int now = 0;
        int times = 0;

        while(!pass[now]) {
            pass[now] = true;
            th[now] = times++;
            now = A[now];
        }

        if(K < times) {
            now = 0;
            for(int i = 0; i < K; i++) {
                now = A[now];
            }
            os.println(now+1);
            return;
        }

        int interval = times - th[now];

        K = K - th[now];
        long amari = K % interval;

        for(int i = 0; i < amari; i++) {
            now = A[now];
        }

        os.println(now+1);

    }
}
