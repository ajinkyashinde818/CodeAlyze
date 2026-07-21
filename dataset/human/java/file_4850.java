import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = 0;

        if (n %2 != 0) {
            System.out.println(0);
            return;
        }

        long denominator = 10;
        while (n >= denominator) {
            ans += n/denominator;
            denominator *= 5;
        }

        System.out.println(ans);
    }
}
