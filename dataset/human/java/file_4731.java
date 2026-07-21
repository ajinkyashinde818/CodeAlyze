import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main
{
    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskAtCoder solver = new TaskAtCoder();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskAtCoder
    {
        public void solve(int testNumber, Scanner in, PrintWriter out)
        {
            String s = in.next();
            int dp[][] = new int[s.length() + 1][2];
            init_dp(dp, s.length() + 1);
            int[] a = new int[s.length()];
            for (int i = 0; i < s.length(); i++)
            {
                a[i] = Character.getNumericValue(s.charAt(i));
            }
            dp[0][0] = Math.min(a[0], 1 + 10 - a[0]);
            dp[0][1] = Math.min(a[0] + 1, 1 + 10 - a[0] - 1);
            for (int i = 1; i < s.length(); i++)
            {
                dp[i][0] = Math.min(dp[i - 1][0] + a[i], dp[i - 1][1] + 10 - a[i]);
                dp[i][1] = Math.min(dp[i - 1][0] + a[i] + 1, dp[i - 1][1] + 10 - a[i] - 1);
            }

            System.out.println(dp[s.length() - 1][0]);
        }

        static void init_dp(int dp[][], int N)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    dp[i][j] = -1;
                }
            }
        }

    }
}
