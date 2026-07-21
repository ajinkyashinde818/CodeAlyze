import java.util.Scanner;

public class Main {

	static long mod = 1000000007;

	public static void main(String[] args) {
		// AtCoder_B
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int zoro = 0;
		String ans = "No";

		for(int i=0; i<N; i++) {
			if(sc.nextInt() == sc.nextInt()) {
				zoro++;
				if(zoro == 3) {
					ans = "Yes";
				}
			} else {
				zoro = 0;
			}
		}

		System.out.println(ans);

	    // Scannerクラスのインスタンスをクローズ
		sc.close();
	}
}
