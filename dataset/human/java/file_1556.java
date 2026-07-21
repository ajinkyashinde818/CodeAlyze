import java.util.*;
// warm-up
// I thought Atcoder doesnt do time wasters...
public class Main {

	static char[][] g = null;
	static char[][] p = null;

	static void solve() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(), m=sc.nextInt(), t=n, i=0, j=0, c=0, r=0;
		boolean ok = true;
		g = new char[n][n];
		p = new char[m][m];
		while (t-->0) {
			j=0;
			for (char ch : sc.next().toCharArray()) g[i][j++] = ch;
			i++;
		}
		t=m; i=0;
		while (t-->0) {
			j=0;
			for (char ch : sc.next().toCharArray()) p[i][j++] = ch;
			i++;
		}
		i=0; j=0; c=r=n-m; 
		while (i<=r) {
			j=0;
			while (j<=c) {
				ok = true;
				// Check
				for (int l=0; l<m; l++) {
					for (int o=0; o<m; o++) {
						if (p[l][o]!=g[i+l][j+o]) {
							ok=false; break;
						}
					}
					if (!ok) break;
				}
				if (ok) {
					System.out.println("Yes");
					System.exit(0);
				}
				j++;
			}
			i++;
		}
		System.out.println("No");
		sc.close();			
	}

	public static void main(String args[]) {
		solve();
	}

}
