import java.io.PrintWriter;
import java.util.Scanner;

// MainT1P2018D
public class Main {

	public static void main(String[] args) {
		try (Scanner in = new Scanner(System.in);
			 PrintWriter out = new PrintWriter(System.out))
		{
			final int N = in.nextInt();
			int d = 8*N + 1;
			int dr = (int)Math.sqrt(d);
			if (dr * dr != d) {
				out.println("No");
				return;
			}

			final int k = (1 + dr) / 2;

			final int[] startIdx = new int[k - 1];
			{
				int idx = 1;
				for (int i = 0; i < k - 1; ++i) {
					startIdx[i] = idx;
					idx += i + 1;
				}
			}

			out.println("Yes");
			out.println(k);
			{
				out.print(k - 1);
				for (int i = 0; i < k - 1; ++i) {
					out.print(' ');
					out.print(startIdx[i] + i);
				}
				out.println();
			}
			for (int i = 0; i < k - 1; ++i) {
				out.print(k - 1);
				for (int j = 0; j < i; ++j) {
					out.print(' ');
					out.print(startIdx[i] + j);
				}
				for (int j = i; j < k - 1; ++j) {
					out.print(' ');
					out.print(startIdx[j] + i);
				}
				out.println();
			}
		}
	}
}
