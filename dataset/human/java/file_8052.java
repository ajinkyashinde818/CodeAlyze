import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long y = sc.nextLong();
        long a = Math.max(x, y);
        long b = Math.min(x, y);
        while (true) {
            b += Math.min(x, y);
            if (b % a == 0) {
                System.out.println(b);
                System.exit(0);
            }
        }
    }
}
