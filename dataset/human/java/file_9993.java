import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static final int MOD = 1000000007;
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		int n = parseInt(sc.next());
		int m = parseInt(sc.next());
		int x = parseInt(sc.next());
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for (i = 0; i < n; i++) {
			c[i] = parseInt(sc.next());
			for (j = 0; j < m; j++) {
				a[i][j] = parseInt(sc.next());
			}
		}
		sc.close();
		int ans=12000001;
		int[] b = new int[m];
		for (int k = 0; k < pow(2,n); k++) {
			Arrays.fill(b, 0);
			int mask=1;
			int yen=0;
			for (int l = 0; l < n; l++) {
				if((k&mask)!=0) {
					yen+=c[l];
					for (int p = 0; p < m; p++) {
						b[p]+=a[l][p];
					}
				}
				mask<<=1;
			}
			boolean f =true;
			for (int p = 0; p < m; p++) {
				if(b[p]<x) {
					f= false;
					break;
				}
			}
			if(f) {
				ans=Math.min(ans, yen);
			}
		}
		if(ans==12000001) {
			ans=-1;
		}
		out.println(ans);
	}
}
