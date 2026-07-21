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
        int N = scan.nextInt();
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < N; i++) {
            int d1 = scan.nextInt();
            int d2 = scan.nextInt();
            if (d1 == d2) {
                count += 1;
                max_count = Math.max(max_count, count);
            } else {
                count = 0;
            }
        }
        if (3 <= max_count) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
