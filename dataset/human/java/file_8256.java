import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
        public static void main(String[] args) throws Exception {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                StringTokenizer st;
                PrintWriter pw = new PrintWriter(System.out);

                st = new StringTokenizer(br.readLine());
                long a = Long.parseLong(st.nextToken());
                long b = Long.parseLong(st.nextToken());
                pw.println(lcm(a,b));



                pw.flush();
                pw.close();
        }

        static long lcm(long a, long b) {
                return a*b/gcd(a,b);
        }

        static long gcd(long a, long b) {
                return b==0?a:gcd(b,a%b);
        }
}
