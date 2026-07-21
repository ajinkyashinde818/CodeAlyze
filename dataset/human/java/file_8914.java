import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int A = scan.nextInt();
        int B = scan.nextInt();
        int K = scan.nextInt();
        int gcd = gcd(A, B);
        int n = 0;
        int answer = 0;
        for(int i = gcd; n < K; i-- ) {
            if (gcd % i == 0) {
                n += 1;
                answer = i;
            }
        }
        System.out.println(answer);
    }
    private static int gcd(int m, int n) {
        if (n == 0) {
            return m;
        }
        return gcd(n, m%n);
    }
}
