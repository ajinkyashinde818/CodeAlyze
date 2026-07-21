import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        S = S.replaceAll("eraser", "");
        S = S.replaceAll("erase", "");
        S = S.replaceAll("dreamer", "");
        S = S.replaceAll("dream", "");
        boolean ans = S.isEmpty();
        if (ans) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

    }

}
