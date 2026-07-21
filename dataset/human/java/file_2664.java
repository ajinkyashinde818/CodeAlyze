import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String t = sc.next();

        char[] s_char = s.toCharArray();
        char[] t_char = t.toCharArray();

        Arrays.sort(s_char);
        Arrays.sort(t_char);

        String sorted_s = new String(s_char);
        String sorted_t = new String(t_char);
        sorted_t = new StringBuilder(sorted_t).reverse().toString();

        if (sorted_s.compareTo(sorted_t) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
