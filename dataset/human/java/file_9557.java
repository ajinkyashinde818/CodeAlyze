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
            int T = 1;
            while (T-- > 0)
            {
                solveOne(in, out);
            }
        }

        private void solveOne(Scanner in, PrintWriter out)
        {
            int N = in.nextInt();
            int M[][] = CPUtils.readIntMatrix(N, 2, in);

            for (int i = 0; i < N - 2; i++)
            {
                if (M[i][0] == M[i][1] && M[i + 1][0] == M[i + 1][1] && M[i + 2][0] == M[i + 2][1])
                {
                    out.println("Yes");
                    return;
                }
            }
            out.println("No");
        }

    }

    static class CPUtils
    {
        public static int[] readIntArray(int size, Scanner in)
        {
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = in.nextInt();
            }
            return array;
        }

        public static int[][] readIntMatrix(int rows, int columns, Scanner in)
        {
            int[][] matrix = new int[rows][columns];
            for (int i = 0; i < rows; i++)
            {
                matrix[i] = CPUtils.readIntArray(columns, in);
            }
            return matrix;
        }

    }
}
