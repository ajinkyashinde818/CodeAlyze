import java.util.*;

public class Main {

    private static final int INF = 1_000_000_000;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] A = new int[N+1];
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }

        if (K <= N) {
            int pos = 1;
            for (int i = 0; i < K; i++) {
                pos = A[pos];
            }
            System.out.println(pos);
            return;
        }

        boolean[] visited = new boolean[N+1];
        int x = 1;
        while (!visited[x]) {
            visited[x] = true;
            x = A[x];
        }

        int preLen = 0;
        int pos = 1;
        while (pos != x) {
            pos = A[pos];
            preLen++;
        }

        int len = 1;
        pos = A[x];
        while (pos != x) {
            pos = A[pos];
            len++;
        }

        int modPos = (int)((K-preLen)%len);
        int ans = x;
        for (int i = 0; i < modPos; i++) {
            ans = A[ans];
        }

        /*
        System.out.println(preLen);
        System.out.println(x);
        System.out.println(len);
        */

        System.out.println(ans);
    }
}
