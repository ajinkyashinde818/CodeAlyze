import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static int gcd(int a, int b) {
        return (b != 0) ? gcd(b, a % b) : a;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int m = s.nextInt();
        int k = s.nextInt();

        ArrayList<Integer> divisors = new ArrayList<>();
        int g = gcd(n, m);
        for (int i = g + 1; i >= 1; i--) {
            if ((g % i) == 0) {
                k--;
                if (k == 0) {
                    System.out.println(i);
                    System.exit(0);
                }
            }
        }
    }
}
