import java.util.Scanner;

public class Main {
    final double EPS = 1.0e-10;
    final int INF = 1 << 22;
    int m;
    int n;
    int bs[];

    void run() {
        Scanner sc = new Scanner(System.in);
        while (true) {
            m = sc.nextInt();
            n = sc.nextInt();
            if ((n | m) == 0)
                break;
            bs = new int[n];
            int max = 0;
            for (int i = 0; i < n; i++) {
                bs[i] = sc.nextInt();
                max = Math.max(bs[i], max);
            }
            int lb = max;
            int ub = INF;
            while (ub - lb > 1) {
                int mid = (lb + ub) / 2;
                if (c(mid)) {
                    ub = mid;
                } else {
                    lb = mid;
                }
            }
            System.out.println(lb);
        }
    }

    boolean c(int w) {
        int num = 1;
        int st = 0;
        for (int i = 0; i < n; i++) {
            if (st + bs[i] >= w) {
                num++;
                st = bs[i];
                if (num > m)
                    return false;
            } else {
                st += bs[i];
            }
        }
        return true;
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
