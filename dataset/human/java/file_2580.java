import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    private static boolean isLessThan(String[] a, String[] b) {
        for (int i = 0; i < Math.min(a.length, b.length); i++) {
            if (a[i].compareTo(b[i]) < 0) {
                return true;
            } else if (a[i].compareTo(b[i]) > 0) {
                return false;
            }
        }
        return a.length < b.length;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        String[] sa = s.split("");
        String[] ta = t.split("");
        Arrays.sort(sa);
        Arrays.sort(ta, Collections.reverseOrder());
        StringJoiner sjs = new StringJoiner("");
        for (int i = 0; i < sa.length; i++) {
            sjs.add(sa[i]);
        }
        StringJoiner sjt = new StringJoiner("");
        for (int i = 0; i < ta.length; i++) {
            sjt.add(ta[i]);
        }
        if (isLessThan(sa, ta)) {
            System.out.println("Yes");
            return;
        }
        System.out.println("No");
    }

}
