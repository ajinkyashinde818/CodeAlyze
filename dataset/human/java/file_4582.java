import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        if (c > (a + b)) {
            System.out.println(2 * b + a + 1);
        } else {
            System.out.println(b + c);
        }
    }
}
