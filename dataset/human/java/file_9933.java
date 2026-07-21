import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task
    {
        public void solve(int testNumber, Scanner in, PrintWriter out)
        {
            int N = in.nextInt();
            int M = in.nextInt();
            int X = in.nextInt();
            int[][] books = read(in, N, M + 1);
            int minCost = Integer.MAX_VALUE;
            for (int combination = 0; combination < 1 << N; combination++)
            {
                int knoweldge[] = new int[M];
                int cost = 0;
                for (int book = 1; book <= N; book++)
                {
                    boolean isTaken = CPUtils.getIthBitFromInt(combination, book) != 0;
                    for (int algo = 1; algo <= M && isTaken; algo++)
                    {
                        knoweldge[algo - 1] += books[book - 1][algo];
                    }
                    cost += isTaken ? books[book - 1][0] : 0;
                }
                int cnt = 0;
                for (int i = 0; i < knoweldge.length; i++)
                {
                    cnt += knoweldge[i] >= X ? 1 : 0;
                }
                if (cnt == M)
                {
                    minCost = Math.min(minCost, cost);
                }
            }
            out.println(minCost == Integer.MAX_VALUE ? -1 : minCost);
        }

        private int[][] read(Scanner in, int n, int m)
        {
            int[][] books = new int[n][m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    books[i][j] = in.nextInt();
                }
            }
            return books;
        }

    }

    static class CPUtils
    {
        public static int getIthBitFromInt(int bits, int i)
        {
            return (bits >> (i - 1)) & 1;
        }

    }
}
