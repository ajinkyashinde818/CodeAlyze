import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        while (n > 0) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = in.nextInt();
            }

            String s = in.next();
            int m = s.length();

            for (int i = 0; i < m; i++) {
                out.print(toChar((toIndex(s.charAt(i)) + 52 - k[i % n]) % 52));
            }
            out.println();

            n = in.nextInt();
        }

        out.flush();
    }

    private static int toIndex(char c) {
        if ('a' <= c && c <= 'z') {
            return c - 'a';
        } else {
            return c - 'A' + 26;
        }
    }

    private static char toChar(int index) {
        if (index < 26) {
            return (char) (index + 'a');
        } else {
            return (char) (index - 26 + 'A');
        }
    }

}
