import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = scan.nextInt();
        long[] a = new long[n];
        long total = 0;
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextLong();
            total += a[i];
        }
        long[] s = new long[n+1];
        for (int i = 0; i < n; i++) {
            s[i+1] = s[i] + a[i];
        }
        long answer = Long.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            if (Math.abs(2 * s[i] - total) < answer) {
                answer = Math.abs(2 * s[i] - total);
            }
        }
        System.out.println(answer);
    }
}
