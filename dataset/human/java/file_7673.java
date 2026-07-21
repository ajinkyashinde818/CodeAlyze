import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long k = in.nextLong();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }

        int t[] = new int[2 * 100_000];
        Arrays.fill(t, -1);
        t[0] = 0;
        int pos = 0;
        int count = 1;
        int period = 0;
        int stepAtLoopStart = 0;
        int loopStart = 0;
        while (true) {
            int next = a[pos];
            if (t[next] != -1) {
                period = count - t[next];
                stepAtLoopStart = t[next];
                loopStart = next;
                break;
            }
            t[next] = count;
            count++;
            pos = next;
        }

        if (k < stepAtLoopStart) {
            int now = 0;
            for (int i = 0; i < k; i++) {
                now = a[now];
            }
            System.out.println(now + 1);
        } else {
            long step = k - stepAtLoopStart;
            step %= period;
            int now = loopStart;
            for (int i = 0; i < step; i++) {
                now = a[now];
            }
            System.out.println(now + 1);
        }
    }
}
