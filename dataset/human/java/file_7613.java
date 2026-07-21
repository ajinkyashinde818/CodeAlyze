import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.LinkedHashSet;
import java.util.ArrayList;

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
            long K = in.nextLong();
            int moves[] = CPUtils.readIntArray(N, in);

            List<Integer> t = new ArrayList<>(N);
            Set<Integer> visited = new LinkedHashSet<>(N);
            visited.add(1);
            t.add(1);

            long tempK = K;
            int current = 1;
            int repeat = -1;
            while (tempK > 0)
            {
                int next = moves[current - 1];
                if (visited.contains(next))
                {
                    repeat = next;
                    break;
                }
                current = next;
                t.add(current);
                visited.add(current);
                tempK--;
            }
            int repeat_start_index = t.indexOf(repeat);

            if (repeat_start_index == -1)
            {
                out.println(t.get((int) K));
                return;
            }

            K -= repeat_start_index;

            int cycle_size = t.size() - repeat_start_index;

            int offset = (int) (K % cycle_size);
            out.println(t.get(repeat_start_index + offset));
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
