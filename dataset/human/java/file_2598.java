import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String t = sc.next();

        String[] ss = new String[s.length()];
        for (int i = 0; i < s.length(); i++) {
            ss[i] = String.valueOf(s.charAt(i));
        }
        Arrays.sort(ss);

        String[] tt = new String[t.length()];
        for (int i = 0; i < t.length(); i++) {
            tt[i] = String.valueOf(t.charAt(i));
        }
        Arrays.sort(tt, Comparator.reverseOrder());

        int lim = Math.max(s.length(), t.length());
        String ans = "No";
        for (int i = 0; i < lim; i++) {
            int sVal = ss[i].codePointAt(0);
            int tVal = tt[i].codePointAt(0);

            System.err.printf("%s %s \n", sVal, tVal);
            if (sVal == tVal) {
                if (i + 1 >= ss.length && ss.length < tt.length) {
                    ans = "Yes";
                    break;
                } else if (i + 1 >= tt.length && ss.length > tt.length) {
                    ans = "No";
                    break;
                }
                continue;
            }

            if (sVal < tVal) {
                ans = "Yes";
                break;
            } else {
                ans = "No";
                break;
            }
        }

        System.out.println(ans);
    }
}
