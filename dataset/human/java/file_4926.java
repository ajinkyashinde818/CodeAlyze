import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        long n = scan.nextLong();
        if (n % 2 == 1) {
            System.out.println(0);
            return;
        }
        String s = Long.toString(n);
        long answer = n/10;
        long current = 50;
        while (current <= n) {
            answer += n / current;
            current *= 5;
        }
        System.out.println(answer);
    }
}
