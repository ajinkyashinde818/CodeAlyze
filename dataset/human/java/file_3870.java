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
        String S = scan.next();
        char[] data = S.toCharArray();
        int length = data.length;
        int left = 0;
        int right = length - 1;
        int ans = 0;
        while (left < right) {
            if (data[left] == data[right]) {
                left += 1;
                right -= 1;
                continue;
            }
            if (data[left] != 'x' && data[right] != 'x') {
                System.out.println(-1);
                return;
            }
            if(data[left] == 'x') {
                ans += 1;
                left += 1;
            }
            if(data[right] == 'x') {
                ans += 1;
                right -= 1;
            }
        }
        System.out.println(ans);
    }
}
