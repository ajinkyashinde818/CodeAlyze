import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            String[] in = br.readLine().split(" ");
            int n = Integer.parseInt(in[0]);
            int m = Integer.parseInt(in[1]);
            int x = Integer.parseInt(in[2]);
            int[] c = new int[n];
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                in = br.readLine().split(" ");
                c[i] = Integer.parseInt(in[0]);
                for (int j = 0; j < m; j++) {
                    a[i][j] = Integer.parseInt(in[j + 1]);
                }
            }

            br.close();

            int ans = (int) 1e9;
            for (int bit = 0; bit < (1 << n); bit++) {
                int acc = 0;
                int[] tmp = new int[m];
                for (int i = 0; i < n; i++) {
                    if ((bit >> i & 1) == 1) {
                        acc += c[i];
                        for (int j = 0; j < m; j++) {
                            tmp[j] += a[i][j];
                        }
                    }
                }
                boolean check = true;
                for (int i = 0; i < m; i++) {
                    if (tmp[i] < x) {
                        check = false;
                    }
                }
                if (check) {
                    ans = Math.min(ans, acc);
                }
            }

            PrintWriter pw = new PrintWriter(System.out);

            pw.println((ans == (int) 1e9) ? -1 : ans);

            pw.flush();

        }
    }
}
