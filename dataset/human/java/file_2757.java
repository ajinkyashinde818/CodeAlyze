import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    static void solve(Scanner sc) {
        char[] a = sc.next().toCharArray();
        char[] b = sc.next().toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        String as = String.valueOf(a);
        String bs = new StringBuilder(String.valueOf(b)).reverse().toString();
        System.out.println(as.compareTo(bs) < 0 ? "Yes" : "No");
    }
}
