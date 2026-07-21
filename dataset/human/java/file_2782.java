import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            String s = in.next();
            String t = in.next();

            char[] S = s.toCharArray();
            Arrays.sort(S);

            char[] T = t.toCharArray();
            Arrays.sort(T);
            for (int l = 0, r = T.length - 1; l < r; l++, r--) {
                char swap = T[l];
                T[l] = T[r];
                T[r] = swap;
            }

            System.out.println(new String(S).compareTo(new String(T)) < 0 ? "Yes" : "No");
        }
    }
}
