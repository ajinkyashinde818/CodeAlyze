import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            String S = in.next();
            char[] cs = S.toCharArray();
            Arrays.sort(cs);
            System.out.println("abc".equals(new String(cs)) ? "Yes" : "No");
        }
    }
}
