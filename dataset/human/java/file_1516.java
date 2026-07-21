import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for(int i = 0 ; i < n ; i++) a[i] = sc.next();
		for(int i = 0 ; i < m ; i++) b[i] = sc.next();
		for(int i = 0 ; i <= n - m ; i++) {
			for(int j = 0 ; j <= n - m ; j++) {
				boolean ok = true;
				for(int k = 0 ; k < m ; k++) {
					for(int l = 0 ; l < m ; l++) {
						int x = i + k;
						int y = j + l;
						if(a[x].charAt(y) != b[k].charAt(l)) {
							ok = false;
						}
					}
				}
				if(ok == true) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}
