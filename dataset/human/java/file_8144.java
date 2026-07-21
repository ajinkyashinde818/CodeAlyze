import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = Long.parseLong(sc.next());
        long B = Long.parseLong(sc.next());

        long ans = A * B / gcd(A, B);
        System.out.println(ans);
    }

    public static long gcd(long a, long b) {
        if(a < b) return gcd(b, a);
        if(b == 0) return a;
        return gcd(b, a % b);
    }
}
