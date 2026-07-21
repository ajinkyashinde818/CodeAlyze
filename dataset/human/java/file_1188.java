import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); long sum = 0;
		long[] A = new long[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
			sum += A[i];
		}
		long ans = Long.MAX_VALUE, sn_sum = 0;
		for(int i = 0; i < N - 1; i++) {
			sn_sum += A[i];
			ans = Math.min(ans, Math.abs(sn_sum - (sum - sn_sum)));
		}
		System.out.println(ans);
	}
}
