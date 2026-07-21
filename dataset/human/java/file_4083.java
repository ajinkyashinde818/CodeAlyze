import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = null;
		PrintStream out = null;
		try {
			sc = new Scanner(System.in);
			out = System.out;
			exec(sc, out);
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			if(out != null) {
				out.close();
			}
			if(sc != null) {
				sc.close();
			}
		}
		System.exit(0);
	}
	public static void exec(final Scanner sc, final PrintStream out) throws Exception{
		final int N = sc.nextInt();
		final int A[] = new int[N];
		final int B[] = new int[N];
		final int C[] = new int[N-1];

		for(int i=0;i<N;i++) {
			A[i] = sc.nextInt();
		}
		for(int i=0;i<N;i++) {
			B[i] = sc.nextInt();
		}
		for(int i=0;i<N-1;i++) {
			C[i] = sc.nextInt();
		}
		int score = B[A[0]-1];
		for(int i=1;i<N;i++) {
			score += B[A[i]-1];
			if(A[i-1]+1 == A[i]) {
				score += C[A[i-1]-1];
			}
		}

		out.println(score);
	}
}
