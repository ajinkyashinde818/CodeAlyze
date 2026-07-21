import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int x = in.nextInt();

        int c[] = new int[n];
        int a[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }

        int select = 0;
        int min = Integer.MAX_VALUE;
        int understands[] = new int[m];
        while (select < powLong(2, n)) {
            Arrays.fill(understands, 0);
            int cost = 0;
            int currentSelect = select;
            for (int i = 0; i < n; i++) {
                if ((currentSelect & 1) == 1) {
                    for (int j = 0; j < m; j++) {
                        understands[j] += a[i][j];
                    }
                    cost += c[i];
                }
                currentSelect >>= 1;
            }

            if (allOk(understands, x)) {
                min = Math.min(cost, min);
            }

            select++;
        }

        if (min == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }

    static final boolean allOk(int understands[], int x) {
        for (int i = 0; i < understands.length; i++) {
            if (understands[i] < x) {
                return false;
            }
        }
        return true;
    }

    static final long powLong(long a, long e) {
        long r = 1;
        while (e > 0) {
            if ((e & 1) == 1) {
                r *= a;
            }
            e = e >> 1;
            a *= a;
        }

        return r;
    }
}
