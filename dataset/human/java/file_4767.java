import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		int keta = 0;
		long ans = 0;
		if(n % 2 == 1) {
			System.out.println(0);
		} else {
			long tmp = n;
			tmp /= 10;
			while(tmp != 0) {
				ans += tmp;
				tmp /= 5;
			}
			System.out.println(ans);
		}

	}

}
