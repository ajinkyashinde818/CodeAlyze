import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long c = sc.nextLong();
		long[] x = new long[n + 1];
		long[] v = new long[n + 1];
		long[] vsum = new long[n + 1];
		vsum[0] = 0;
		for(int i = 1; i < n + 1; i++) {
			x[i] = sc.nextLong();
			v[i] = sc.nextLong();
			vsum[i] = vsum[i - 1] + v[i];
		}
		long[] clo = new long[n + 1];
		long[] unc = new long[n + 1];
		clo[0] = 0;
		unc[0] = 0;
		long[] clodis = new long[n + 1];
		long[] uncdis = new long[n + 1];
		clodis[0] = 0;
		uncdis[0] = 0;
		for(int i = 1; i < n + 1; i++) {
			if(clo[i - 1] < vsum[i] - x[i]) {
				clo[i] = vsum[i] - x[i];
				clodis[i] = x[i];
			} else {
				clo[i] = clo[i - 1];
				clodis[i] = clodis[i - 1];
			}
		}
		for(int i = n; i > 0; i--) {
			if(i == n) {
				if(0 < vsum[n] - vsum[n - 1] - (c - x[n])) {
					unc[n] = vsum[n] - vsum[n - 1] - (c - x[n]);
					uncdis[n] = c - x[n];
				} else {
					unc[n] = 0;
					uncdis[n] = 0;
				}
			} else {
				if(unc[i + 1] < vsum[n] - vsum[i - 1] - (c - x[i])) {
					unc[i] = vsum[n] - vsum[i - 1] - (c - x[i]);
					uncdis[i] = c - x[i];
				} else {
					unc[i] = unc[i + 1];
					uncdis[i] = uncdis[i + 1];
				}
			}
		}
		long ans = 0;
		for(int i = 0; i < n + 1; i++) {
			long tmp = clo[i];
			if(i != n) {
				tmp += unc[i + 1];
				tmp -= Math.min(clodis[i], uncdis[i + 1]);
			}
			ans = Math.max(ans, tmp);
		}
		System.out.println(ans);
	}

}
