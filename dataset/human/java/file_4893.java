import java.util.Scanner;

public class Main {
	static long solve(long N){
		if(N % 2 == 1){
			return 0;
		}
		long m = 5;
		long S = 0;
		while(m < N){
			S += N / (m * 2);
			m = m * 5;
		}
		return S;
	}
	public static void main(String[] args) {
//		for(int N = 1 ; N <= 100 ; ++N){
//			System.out.println(N+" "+solve(N));
//		}
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		System.out.println(solve(N));
	}
}
