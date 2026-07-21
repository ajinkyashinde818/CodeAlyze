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
            int K = in.nextInt();
            int N = in.nextInt();
            int nums[] = CPUtils.readIntArray(N, in);
            int distance = Integer.MAX_VALUE;
            for (int i = 0; i < nums.length; i++)
            {
                distance = Math.min(distance, getD(i, i + (nums.length - 1), nums, K));
            }
            out.print(distance);
        }

        private int getD(int start, int end, int nums[], int K)
        {
            end = end % nums.length;
            if (nums[end] < nums[start])
            {
                return (K - nums[start] + nums[end]);
            } else
            {
                return nums[end] - nums[start];
            }
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

    }
}
