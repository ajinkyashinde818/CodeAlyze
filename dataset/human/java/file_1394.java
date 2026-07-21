import java.util.*;
public class Main {

	static int n, m;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		String a[] = new String[n];
		String b[] = new String[m];
		String found = "No";
		for(int i = 0; i < n; i++) {
			a[i] = sc.next();
		}
		for(int i = 0; i < m; i++) {
			b[i] = sc.next();
		}
		out: for(int i = 0; i <= n - m; i++) {
			for(int j = 0; j <= n - m; j++) {
				if(equalImg(a, b, i, j)) {
					found = "Yes";
					break out;
				}
			}
		}
		System.out.println(found);
	}
	static boolean equalImg(String[] a, String[] b, int dx, int dy) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i + dy].charAt(j + dx) != b[i].charAt(j)) return false;
			}
		}
		return true;
	}
}
