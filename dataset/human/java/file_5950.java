import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        char[] c = S.toCharArray();
        Arrays.sort(c);
        if (c[0] == 'a' && c[1] == 'b' && c[2] == 'c') {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

}
