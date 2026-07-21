import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		String answer = "No";
		String[][] ary1 = new String[n][n];

		for (j = 0; j < n; j++) {
			String str = s.next();
			for (i = 0; i < n; i++) {
				ary1[j][i] = str.charAt(i) + "";
			}
		}

		String[][] ary2 = new String[m][m];
		for (l = 0; l < m; l++) {
			String str2 = s.next();
			for (k = 0; k < m; k++) {
				ary2[l][k] = str2.charAt(k) + "";
				//System.out.println(ary2[l][k]);
			}
		}

		b:for (j = 0; j+m <= n; j++) {
			for (i = 0; i+m <= n; i++) {
				a: for (l = 0; l < m; l++) {
					for (k = 0; k < m; k++) {
						if (ary1[j + l][i + k].equals(ary2[l][k])) {
						} else {
							break a;
						}
					}
				}
				if(k==m&&l==m) {
					answer = "Yes";
					break b;
				}
			}
		}
		System.out.println(answer);

	}

}
