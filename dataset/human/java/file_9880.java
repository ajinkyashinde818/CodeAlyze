import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int x = Integer.parseInt(sc.next());
        Integer[] c = new Integer[n];
        Integer[][] a = new Integer[n][m];
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(sc.next());
            for (int j = 0; j < m; j++) {
                a[i][j] = Integer.parseInt(sc.next());
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 1 << n; i++) {
            Integer[] s = new Integer[m];
            int p = 0;
            Arrays.fill(s, 0);
            for (int j = 0; j < n; j++) {
                if ((i >> j & 1) != 1) continue;
                p += c[j];
                for (int k = 0; k < m; k++) {
                    s[k] += a[j][k];
                }
            }
            boolean f = true;
            for (Integer t : s) {
                if (t < x) {
                    f = false;
                    break;
                }
            }
            if (f) {
                ans = Math.min(ans, p + 1);
            }
        }
        out.println(ans % Integer.MAX_VALUE - 1);
        out.flush();
    }
}
