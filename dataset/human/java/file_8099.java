import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        long A = scan.nextLong();
        long B = scan.nextLong();
        long gcd = gcd(A, B);
        long lcm = A * B / gcd;
        System.out.println(lcm);
    }
    private long gcd(long x, long y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x%y);
    }
}
