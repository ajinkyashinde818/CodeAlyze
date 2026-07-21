import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}

	Scanner sc = new Scanner(System.in);

	void run() {
		int n = sc.nextInt();
		long c = sc.nextLong();

		long x[] = new long[n];
		long v[] = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextLong();
			v[i] = sc.nextLong();
		}

		long cw[] = new long[n + 1];
		long cwv[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			cwv[i + 1] = cwv[i] + v[i];
			cw[i + 1] = cwv[i + 1] - x[i];
		}

		long cc[] = new long[n + 1];
		long ccv[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			int j = n - i - 1;
			ccv[i + 1] = ccv[i] + v[j];
			cc[i + 1] = ccv[i + 1] - c + x[j];
		}
//		System.out.println(Arrays.toString(cw));
//		System.out.println(Arrays.toString(cc));
		long cwMax[] = new long[n+1];
		long ccMax[] = new long[n+1];
		
		ccMax[0] = cc[0];
		cwMax[0] = cw[0];
		for(int i = 1; i < n+1;i++){
			ccMax[i] = Math.max(ccMax[i-1] , cc[i]); 
			cwMax[i] = Math.max(cwMax[i-1] , cw[i]); 
		}
//		System.out.println(Arrays.toString(cwMax));
//		System.out.println(Arrays.toString(ccMax));
		long res = 0;
		
		for(int i = 0; i < n+1;i++){
			int j = n - i;
			
			if (i == 0 || j == 0) {
//				System.out.println(i+" "+j+" : " + (cwMax[i] + ccMax[j]));
				res = Math.max(res, cwMax[i] + ccMax[j] );
			} else {
//				System.out.println(i+" "+j+" : " +x[i-1]+","+ (c - x[n - j ]) + " :" + (cwMax[i] + ccMax[j]-Math.min(x[i-1], c - x[n - j ])));
				res = Math.max(res, cwMax[i] + ccMax[j] - Math.min(x[i-1], c - x[n - j ]));
			}
		
		}
		
		System.out.println(res);
	}
}
