import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] arrN = new String[n];
		String[] arrM = new String[m];
		for (int i = 0; i < n; i++) {
			arrN[i] = sc.next();
		}
		for (int i = 0; i < m; i++) {
			arrM[i] = sc.next();
		}
		
		for (int i = 0; i + m <= n; i++) {
			for (int j = 0; j + m <= n; j++) {
				boolean flag = true;
				for (int k = 0; k < m; k++) {
					for (int l = 0; l < m; l++) {
						if (arrM[k].charAt(l) != arrN[i + k].charAt(j + l)) {
							flag = false;
							break;
						}
					}
					if (!flag) {
						break;
					}
				}
				if (flag) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}
