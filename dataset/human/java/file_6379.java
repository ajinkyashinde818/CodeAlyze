import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            final String s = reader.readLine();

            final String[] sl = s.split(" ");
            int K = Integer.parseInt(sl[0]);
            int S = Integer.parseInt(sl[1]);

            int cnt = 0;

            for (int x = 0; x <= K; x++) {
                for (int y = 0; y <= K; y++) {
                    if (x + y <= S) {
                        int z = S - x - y;
                        if (z <= K) cnt++;
                    }
                }
            }

            System.out.println(cnt);
        }
    }
}
