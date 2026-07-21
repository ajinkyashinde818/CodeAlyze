import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = Integer.parseInt(sc.next());
        int N = Integer.parseInt(sc.next());
        int[] A = new int[N];
        Integer[] dist = new Integer[N];
        int time = 0;

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(sc.next());
        }

        for (int i = 0; i < N - 1; i++) {
            dist[i] = Math.abs(A[i + 1] - A[i]);
        }

        dist[N - 1] = Math.abs(A[0] + K - A[N - 1]);

        Arrays.sort(dist, Collections.reverseOrder());
        for (int i = 1; i < N; i++) {
            time += dist[i];
        }

        PrintWriter out = new PrintWriter(System.out);
        out.println(time);
        out.flush();
        sc.close();
    }
}
