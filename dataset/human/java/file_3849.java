import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        String s = scanner.next();
        char[] t = s.replace("x", "").toCharArray();
        int[] c = new int[t.length + 1];

        for (int i = 0; i < (t.length + 1) / 2; i++) {
            if (t[i] != t[t.length - i - 1]) {
                System.out.println(-1);
                return;
            }
        }

        for (int i = 0, j = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'x') {
                c[j]++;
            } else {
                j++;
            }
        }

        long ans = 0;
        for (int i = 0; i < (t.length + 1) / 2; i++) {
            ans += Math.abs(c[i] - c[t.length - i]);
        }

        System.out.println(ans);
    }
}
