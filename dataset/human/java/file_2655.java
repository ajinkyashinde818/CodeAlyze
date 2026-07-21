import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static Scanner sc;

    public Main() {
    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        new Main().solve();

    }

    private void solve() {
        String s = sc.next();
        String t = sc.next();

        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();

        Arrays.sort(sc);
        Arrays.sort(tc);
        if (new StringBuilder(new String(tc)).reverse().toString()
                .compareTo(new StringBuilder(new String(sc)).toString()) <= 0) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
