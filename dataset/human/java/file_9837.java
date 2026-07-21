import java.util.Scanner;


public class Main {

//	final int MOD = 1000000007;

	public static int min = 3000000;

	public static void main(String[] args) {

		int ans = 0;
		Scanner sc = new Scanner(System.in);
		boolean f = false;

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int[] c = new int[n];

		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}

//		String string = sc.next();
//		String[] s = string.split("");

//		int[] ans = new int[n];

//		ArrayList<Integer> list = new ArrayList<>();


		//-------------------------------------------------------------------------------------


		for(int i = 0; i < (1<<n); i++) {
			int[] xnum = new int[m];
			int maney = 0;
			f = true;
			for(int j = 0; j < n; j++) {
				if((1 & i>>j) == 1) {
					maney += c[j];
					for(int k = 0; k < m; k++) {
						xnum[k] += a[j][k];
					}
				}
			}
			for(int k = 0; k < m; k++) {
				if(xnum[k] < x) {
					f = false;
					break;
				}
			}
			if(f) {
				if(maney < min) {
					min = maney;
				}
			}
		}

		ans = min;
		if(min == 3000000) {
			ans = -1;
		}


		//-------------------------------------------------------------------------------------

//		for(int i = 0; i < n; i++) {
//			System.out.println(ans[i]);
//		}

//		if(f) {
//			System.out.println("Yes");
//		} else {
//			System.out.println("No");
//		}

		System.out.println(ans);

		sc.close();
	}

}
