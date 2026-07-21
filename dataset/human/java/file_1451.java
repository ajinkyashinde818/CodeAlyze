import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		boolean matched = false;
		for(int i = 0; i < n; i++) {
			a[i] = sc.next();
		}
		for(int i = 0; i < m; i++) {
			b[i] = sc.next();
		}
		out:
		for(int y = 0; y < n - m + 1; y++) {
			for(int x = 0; x < n - m + 1; x++) {
				for(int k = 0; k < m; k++) {
					if(!(a[y + k].substring(x, x + m).equals(b[k]))) break;
					if(k == m - 1) {
						matched = true;
						break out;
					}
				}
			}
		}
		if(matched) System.out.println("Yes");
		else System.out.println("No");
	}
}
