import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        char[] scha = s.toCharArray();
        char[] tcha = t.toCharArray();
        Arrays.sort(scha);
        Arrays.sort(tcha);
        int scnt = scha.length;
        int tcnt = tcha.length;
        boolean minIsS = true;
        if (scnt > tcnt) {
            minIsS = false;
        }
        int ans = -1;
        for (int i = 0; i < Math.min(scnt, tcnt); i++) {
            if (scha[i] == tcha[tcnt - 1 - i])
                continue;
            if (scha[i] < tcha[tcnt - 1 - i]) {
                ans = 1;
                break;
            } else {
                ans = 0;
                break;
            }
        }
        if (ans == -1) {
            if (scnt == tcnt) {
                ans = 0;
            } else if (scnt < tcnt) {
                ans = 1;
            }
        }
        if (ans == 1) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }
}
