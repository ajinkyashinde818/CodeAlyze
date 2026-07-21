import java.util.*;

class Main{
public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int m = sc.nextInt();
	String[] a = new String[n];
	String[] b = new String[m];
	for(int i = 0; i < n; i++) {
		a[i] = sc.next();
	}
	for(int i = 0; i < m; i++) {
		b[i] = sc.next();
	}
	boolean exist = false;
	for(int i = 0; i <= n - m; i++) {
		for(int j = 0; j <= n - m; j++) {
			boolean match = true;
			for(int k = 0; k < m; k++) {
				for(int l = 0; l < m; l++) {
					if(a[i + k].charAt(j + l) != b[k].charAt(l)) {
						match = false;
					}
				}
			}
			if(match) {
				exist = true;
			}
		}
	}
	if(exist) {
		System.out.println("Yes");
	} else {
		System.out.println("No");
	}
}
}
