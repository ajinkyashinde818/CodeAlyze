import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();

        char[] cs = s.toCharArray();
        char[] ct = t.toCharArray();

        Arrays.sort(cs);
        Arrays.sort(ct);

        for (int l = 0, r = ct.length - 1; l < r; l++, r--) {
            char tmp = ct[l];
            ct[l] = ct[r];
            ct[r] = tmp;
        }

        if (new String(cs).compareTo(new String(ct)) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
