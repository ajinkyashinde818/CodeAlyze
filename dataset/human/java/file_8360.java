import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner scan = new Scanner(is);
        int A = scan.nextInt();
        int B = scan.nextInt();

        long ans = lcm(A, B);

        os.println(ans);
    }

    static public long lcm(long a, long b) {
        if(a == b)
            return a;

        if(a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }

        long answer =  a*(b/(gcd(a, b)));
        return answer;
    }

    static public long gcd(long a, long b) {
        while(a > 0) {
            long tmpa = a;
            a = b % a;
            b = tmpa;
        }
        return b;
    }
}
