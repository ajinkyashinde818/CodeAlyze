import java.util.Scanner;

public class Main {
	//java11

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long N = sc.nextLong();

		int ans = 0;
		long n = N;
		long before_yakusuu;
		long yakusuu = -1;
		long count = 0;	//指数
		long limit = 0;	//現在の必要上限(1, 2, 3, ...と増やしていく)
		while(n >= 2) {
			before_yakusuu = yakusuu;
			yakusuu = fact(n);
			if(yakusuu == -1) {
				break;
			}

			if(yakusuu != before_yakusuu) {
				count = 1;
				limit = 0;
			}else {
				count++;
			}

			if(count > limit) {
				ans++;
				limit++;
				count = 0;
			}
			n /= yakusuu;
		}

		System.out.println(ans);

	}

	//最小の約数を返す(素因数分解用)
	public static long fact(long n){
		if(n < 2)
			return -1;

		for(long i=2; i<=Math.sqrt(n); i++) {
			if(n % i == 0)
				return i;
		}

		return n;
	}
}
