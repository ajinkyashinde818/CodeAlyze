import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        sc.close();

        char[] aa = a.toCharArray();
        Arrays.sort(aa);
        a = String.valueOf(aa);

        char[] bb = b.toCharArray();
        Arrays.sort(bb);
        b = String.valueOf(bb);
        b = new StringBuilder(b).reverse().toString();

        if (a.compareTo(b) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
