import java.util.*;

class Main {
	Scanner sc;
	int K, N;
	void calc() {
		sc = new Scanner(System.in);
		K = sc.nextInt();
		N = sc.nextInt();
		int max = Integer.MIN_VALUE;
		int a0 = sc.nextInt();
		int last = a0;
		for (int i = 1; i < N; i++) {
			int a = sc.nextInt();
			max = Math.max(max, a-last);
			last = a;
		}
		max = Math.max(max, K-last+a0);
		System.out.println( K-max );
	}
	
	public static void main(String[] args) {
		new Main().calc();
	}
}
