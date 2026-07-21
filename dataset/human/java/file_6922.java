import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;

import java.util.*;

public class Main {
    long MOD = (long) 1e9 + 7;

    InputStream in;
    OutputStream out;

    public Main() {
        this(System.in, System.out);
    }

    public Main(InputStream in, OutputStream out) {
        this.in = in;
        this.out = out;
    }

    void run() {
        Scanner sc = new Scanner(this.in);
        PrintWriter out = new PrintWriter(this.out);

        // write your code
        int k = sc.nextInt(), n = sc.nextInt();
        int[] ds = new int[n];
        for (int i = 0; i < n; i++) {
            ds[i] = sc.nextInt();
        }

        int max = k - ds[n - 1] + ds[0];
        for (int i = 0; i < n - 1; i++) {
            max = Math.max(max, ds[i + 1] - ds[i]);
        }

        out.println(k - max);
        out.flush();
    }

    void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
