import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static boolean f(String s, int tmp, char[] a) {
        int start = tmp - a.length;
        int end = tmp;

        boolean flg = true;

        int idx = 0;

        for (int i = start; i < end; i++) {
            if (start < 0) break;
            if (s.charAt(i) != a[idx]) {
                flg = false;
                break;
            }
            idx++;
        }

        return flg;
    }

    public static void main(String[] args) throws IOException {
        final String YES = "YES";
        final String NO = "NO";

        final char dream[] = {'d','r','e','a','m'};
        final char dreamer[] = {'d','r','e','a','m','e','r'};
        final char erase[] = {'e', 'r', 'a', 's', 'e'};
        final char eraser[] = {'e','r','a','s','e','r'};

        String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        boolean flg = false;

        int tmp = s.length();

        while (0 < tmp) {
            boolean result = false;

            flg = f(s, tmp, dream);
            result = result | flg;
            if (flg) {
                tmp -= dream.length;
                if (tmp == 0) break;
            }

            flg = f(s, tmp, dreamer);
            result = result | flg;
            if (flg) {
                tmp -= dreamer.length;
                if (tmp == 0) break;
            }

            flg = f(s, tmp, erase);
            result = result | flg;
            if (flg) {
                tmp -= erase.length;
                if (tmp == 0) break;
            }

            flg = f(s, tmp, eraser);
            result = result | flg;
            if (flg) {
                tmp -= eraser.length;
                if (tmp == 0) break;
            }

            if (!result) break;
        }

        out.println(flg ? YES : NO);

        out.flush();
    }
}
