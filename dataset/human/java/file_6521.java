import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int k = s.nextInt();
		int l = s.nextInt();
		int i = 0;
		int j = 0;
		int m = 15;
		int count = 0;

		int ans = 0;
		int q = 0;

		for (i = 0; i <= k; i++) {
			for (j = 0; j <= k; j++) {

				q = i + j;
				m = l-q;
				if(m>=0&&0<=i&&i<=k&&j<=k&&m<=k) {

					count++;
				}else {

				}
			}
			j=0;
		}
		System.out.println(count);
	}

}
