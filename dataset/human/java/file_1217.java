import java.util.*;
import java.text.DecimalFormat;
// warm-up
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), no = N, i = 0;
		double min = Double.MAX_VALUE, s = 0, t = 0;
		double[] a = new double[N];
		while (N-->0) {
			double b = sc.nextDouble();
			a[i++] = b; s+=b;
		}
		N = no;
		for (i=N-1; i>0; i--) {
			t+=a[i];
			min = Math.min(Math.abs(s-(2*t)), min);
		}
		System.out.println(new DecimalFormat("#").format(min));
		sc.close();		
	}

	public static void main(String args[]) {
		solve();
	}

}
