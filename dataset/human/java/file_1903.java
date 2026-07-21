import java.util.Scanner;
public class Main {
	
	public static int d;
	public static int g;
	public static int[] p;
	public static int[] c;
	public static int[] s;
	public static int ans;
	
	public static void dfs( int n, int sum, int num, int s1 ) {
		if( n == d ) {
			if( sum < g ) {
				int need = (int)Math.ceil((double)(g - sum)/(100 * (s1+1)));
				if( need < p[s1] )
					ans = Math.min(ans, num+need);
			}
			else
				ans = Math.min(ans, num);
		}
		else {
			sum += s[n];
			num += p[n];
			dfs(n+1, sum, num, s1);
			sum -= s[n];
			num -= p[n];
			s1 = n;
			dfs(n+1, sum, num, s1);
		}
	}
	
	public static void main(String args[] ) {
		Scanner sc = new Scanner(System.in);
		
		d = sc.nextInt();
		g = sc.nextInt();
		p = new int[d];
		c = new int[d];
		s = new int[d];
		
		for( int i = 0; i < d; i++ ) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
			s[i] = p[i] * 100 * (i+1) + c[i];
		}
		
		ans = 0;
		for( int i = 0; i < d; i++ )
			ans += p[i];
		
		dfs( 0, 0, 0, 0 );
		System.out.println( ans );
		
		sc.close();
	}
}
