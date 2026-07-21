import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner sc = new Scanner(is);
        long N = sc.nextLong();
        int ans = 0;
        long originN = N;
        int sqrtN = (int)Math.sqrt(N);
        for(int i = 2; i < sqrtN; i += 2) {

            int e = 0;
            while(N % i == 0) {
                N /= i;
                e++;
            }

            int t = 1;
            while (e >= t) {
                ans++;
                e -= t;
                t++;
            }

            if (i == 2)
                i = 1;
        }
        if(N != 1 && originN % N == 0)
            ans++;

        os.println(ans);
    }
}
