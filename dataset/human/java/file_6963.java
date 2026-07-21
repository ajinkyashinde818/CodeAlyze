import java.util.Scanner;

public class Main {

	public static final MyScanner in = new MyScanner();

	public static void main(String[] args) {

		int K = in.nextInt();
		int N = in.nextInt();
		int[] A = new int[N];
		for(int i=0;i<N;i++)
			A[i] = in.nextInt();

		int from = A[N-1];
		int to = K + A[0];
		int maxLen= to - from;
		
		to = A[0];
		for(int i=1;i<N;i++) {
			from = to;
			to = A[i];
			int len = to - from;
			if(maxLen < len) maxLen = len;
		}

		System.out.println(K - maxLen);

	}


	public static class MyScanner {
		Scanner sc = new Scanner(System.in);
		String next() { return sc.next();}
		int nextInt() { return Integer.valueOf(sc.next());}
		long nextLong() { return Long.valueOf(sc.next()); }
	}
}
