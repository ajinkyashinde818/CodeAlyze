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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA
    {
        public void solve(int testNumber, Scanner in, PrintWriter out)
        {
            int n = in.nextInt();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            int[] c = new int[n];

            //Dishes
            for (int i = 1; i <= n; i++)
            {
                a[i] = in.nextInt();
            }
            //Satisfactions
            for (int i = 1; i <= n; i++)
            {
                b[i] = in.nextInt();
            }
            //C
            for (int i = 1; i < n; i++)
            {
                c[i] = in.nextInt();
            }

            //Eating
            int sat = 0;

            sat += b[a[1]];
            int lastEat = a[1];

            for (int i = 2; i <= n; i++)
            {
                sat += b[a[i]];
                if (lastEat + 1 == a[i])
                {
                    sat += c[a[i - 1]];
                }
                lastEat = a[i];
            }
            out.print(sat);
        }

    }
}
