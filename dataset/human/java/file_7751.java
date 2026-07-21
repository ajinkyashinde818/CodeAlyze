import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		long k = sc.nextLong();

		int[] a = new int[n];
		int[] f = new int[n];

		for ( int i=0; i<n; i++ ) {
			a[i] = sc.nextInt()-1;
		}

		int ls = 0;
		int le = 0;
		int x = 1;
		f[0] = 1;
		int p = a[0];
		while ( le==0 && k>x ) {
			x++;
			if ( f[p]==0 ) {
				f[p] = x;
			} else {
				le = x;
				ls = f[p];
			}
			p = a[p];
		}

		if ( k==x ) {
			System.out.println(p+1);
		} else {
			int pp = (int)(( k - (long)(ls-1) )%(le-ls) + (long)(ls-1));
			int t = 0;
			for ( int i=0; i<pp; i++ ) {
				t = a[t];
			}
			System.out.println(t+1);
		}
	}
}
