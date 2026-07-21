import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static long[] maxPas = new long[5];
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double[] A = new double[N];
		for(int i=0; i<N; i++) {
			A[i] = sc.nextDouble();
		}
		//　偶数だったら、すべてプラスにできる
		//　奇数だったら、一つだけマイナスにできる
		int minusCnt = 0;
		for(int i=0; i<N; i++) {
			if(A[i] < 0) {
				minusCnt ++;
			}
		}
		
		double ans = 0;
		double[] absA = new double[N];
		for(int i=0; i<N; i++) {
			absA[i] = Math.abs(A[i]);
		}
		if(minusCnt % 2 == 0) {
			for(int i=0; i<N; i++) {
				ans += absA[i];
			}
		} else {
			Arrays.sort(absA);
			ans -= absA[0];
			for(int i=1; i<N; i++) {
				ans += absA[i];
			}
		}
		
		System.out.println(BigDecimal.valueOf(Math.round(ans)).toPlainString());
	}
}
