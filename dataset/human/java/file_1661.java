import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        String S = scan.next();
        char[] d = S.toCharArray();
        int[] a = new int[26];
        for (int i = 0; i < N; i++) {
            a[d[i]-'a'] += 1;
        }
        long answer = 1;
        for (int i = 0; i < 26; i++) {
            if (a[i] == 0) {
                continue;
            }
            answer = answer * (a[i] + 1) % 1000000007;
        }
        System.out.println(answer - 1);
    }
}
