import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            String s = in.next();
            StringBuilder sb = new StringBuilder();
            int n = s.length();
            for (int i = 0; i < n; i++) {
                char charAt = s.charAt(i);
                if (charAt != 'x') {
                    sb.append(charAt);
                }
            }
            if (!is(sb)) {
                System.out.println(-1);
                return;
            }

            int count = 0;
            for (int l = 0, r = n - 1; l < r;) {
                char cl = s.charAt(l);
                char cr = s.charAt(r);
                if (cl == cr) {
                    l++;
                    r--;
                    continue;
                }
                if (cl == 'x') {
                    l++;
                    count++;
                    continue;
                }
                if (cr == 'x') {
                    r--;
                    count++;
                    continue;
                }
            }

            System.out.println(count);
        }
    }

    private static boolean is(StringBuilder sb) {
        int n = sb.length();
        for (int i = 0; i < n; i++) {
            if (sb.charAt(i) != sb.charAt(n - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}
