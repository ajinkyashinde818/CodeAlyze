import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int N = Integer.parseInt(scan.next());
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		int[] C = new int[N + 1];
		
		for(int i = 1; i <= N; ++i) {
			int in = Integer.parseInt(scan.next());
			A[i] = in;
		}
		
		for(int i = 1; i <= N; ++i) {
			int in = Integer.parseInt(scan.next());
			B[i] = in;
		}
		
		for(int i = 1; i <= (N - 1); ++i) {
			int in = Integer.parseInt(scan.next());
			C[i] = in;
		}

		int sum = 0;
		
		for(int i = 1; i <= N; ++i) {
			sum += B[A[i]];
			
			if(i > 1 && A[i] == (A[i - 1] + 1)) {
				sum += C[A[i - 1]];
			}
		}
		
		pw.print(sum);
		
		scan.close();
		pw.close();
	}
}
