import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    char[] cs;
    int n;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        cs = sc.nextLine().toCharArray();
        n = cs.length;
    }

    private void solve() {
        int i = 0;
        int j = n - 1;
        long cnt = 0;
        while (i < j) {
            if (cs[i] == cs[j]) {
                i++;
                j--;
            }
            else if (cs[i] == 'x') {
                i++;
                cnt++;
            }
            else if (cs[j] == 'x') {
                j--;
                cnt++;
            }
            else {
                break;
            }
        }
        if (i >= j)
            System.out.println(cnt);
        else
            System.out.println(-1);
    }
}
