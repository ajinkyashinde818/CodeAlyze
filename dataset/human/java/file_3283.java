import java.util.Scanner;

public class Main {
    private static Scanner sc;

    public Main() {
    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        new Main().solve();

    }

    private void solve() {
        String N = sc.next();
        String ans = "No";
        for (int i = 0; i < 2; i++) {
            if (N.charAt(i) == '9') {
                ans = "Yes";
            }
        }
        
        System.out.println(ans);
    }
}
