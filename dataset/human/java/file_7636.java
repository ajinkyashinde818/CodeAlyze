import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            String[] in = br.readLine().split(" ");
            int n = Integer.parseInt(in[0]);
            long k = Long.parseLong(in[1]);
            in = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(in[i]) - 1;
            }

            br.close();

            int now = 0;
            while (k != 0) {
                if (k % 2 == 1) {
                    now = a[now];
                }
                int[] tmp = new int[n];
                for (int i = 0; i < n; i++) {
                    tmp[i] = a[a[i]];
                }
                a = tmp;
                k /= 2;
            }

            System.out.println(now + 1);

        }
    }
}
