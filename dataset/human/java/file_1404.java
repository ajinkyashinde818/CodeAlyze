import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static final long MOD =  1000000007L;
	public static void main(String[] args) {
		int i,j,k,l;
		Scanner sc = new Scanner(in);
		int n = parseInt(sc.next());
		int m = parseInt(sc.next());
		char[][] a = new char[n][];
		for (i = 0; i < n; i++) {
			a[i] = sc.next().toCharArray();
		}
		char[][] b = new char[m][];
		for (i = 0; i < m; i++) {
			b[i] = sc.next().toCharArray();
		}
		sc.close();
		boolean f=true;
LABEL1:	for (i = 0; i <= n-m; i++) {
		for (j = 0; j <= n-m; j++) {
				f=true;
LABEL2:			for (k = 0; k < m; k++) {
					for (l = 0; l < m; l++) {
						if(b[k][l]!=a[k+i][l+j]) {
							f=false;
							break LABEL2;
						}
					}
				}
				if(f)break LABEL1;
			}
		}
		out.println(f?"Yes":"No");
	}
}
