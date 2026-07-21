import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		int N = sc.nextInt();
		long A[] = new long[N];
		for(int i = 0 ; i < N ; ++i){
			A[i] = sc.nextLong();
		}
		long ret = A[N - 1] - A[0];
		for(int i = 1 ; i < N ; ++i){
			long D = A[i - 1];
			D += K - A[i];
			ret = Math.min(D, ret);
		}
		System.out.println(ret);
	}
}
