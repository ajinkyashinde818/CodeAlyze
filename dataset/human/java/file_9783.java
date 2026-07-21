import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int[] c = new int[n];
		int[][] a = new int[n][m];

		for ( int i=0; i<n; i++ ) {
			c[i] = sc.nextInt();
			for ( int j=0; j<m; j++ ) {
				a[i][j] = sc.nextInt();
			}
		}

		// 全部買ってもだめなら絶対だめ
		for ( int j=0; j<m; j++ ) {
			int rki = 0;
			for ( int i=0; i<n; i++ ) {
				rki += a[i][j];
			}
			if ( rki<x ) {
				System.out.println(-1);
				System.exit(0);
			}
		}

		int g = 0;
		// 仮に、合計金額
		for ( int i=0; i<n; i++ ) {
			g += c[i];
		}

		int[] b = new int[n];
		int f = 1;
		while ( f>0 ) {
			f = createbit(b, f);

			int f1 = 0;
			for ( int j=0; j<m; j++ ) {
				int rki = 0;
				for ( int i=0; i<n; i++ ) {
					rki += a[i][j]*b[i];
				}
				if ( rki<x ) {
					f1 = -1;
					break;
				}
			}

			if ( f1==0 ) {
				int g1 = 0;
				for ( int i=0; i<n; i++ ) {
					g1 += c[i]*b[i];
				}
				g = Math.min(g, g1);
			}
		}

		System.out.println(g);
	}

	private static int createbit(int[] ary, int flag){
		int hen = flag;
		for ( int i=ary.length-1; i>=0; i-- ) {
			ary[i] = hen%2;
			hen = hen/2;
		}

		int mod = (int)Math.pow(2, ary.length);
		return (flag+1)%mod;
	}
}
