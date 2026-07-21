import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }

    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        long K = scan.nextLong();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scan.nextInt()-1;
        }
        int loop_length = 1;
        int current = 0;
        Map<Integer, Integer> used = new HashMap<>();
        used.put(0, 1);
        while (!used.containsKey(A[current])) {
            current = A[current];
            loop_length += 1;
            used.put(current, loop_length);
        }
        int prefix_length = used.get(A[current])-1;
        if (K <= loop_length) {
            current = 0;
            while(0 < K) {
                current = A[current];
                K -= 1;
            }
            System.out.println(current+1);
            return;
        }
        long remain = K - prefix_length;
        loop_length -= prefix_length;
        remain %= loop_length;
        current = 0;
        while (0 < prefix_length) {
            current = A[current];
            prefix_length -= 1;
        }
        while (0 < remain) {
            current = A[current];
            remain -= 1;
        }
        System.out.println(current+1);
    }
}
