import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		if(N % 2 != 0)
			System.out.println(0);
		else {
			long ans = 0;
			N /= 2;
			while(N > 0) {
				N /= 5;
				ans += N;
			}
			System.out.println(ans);
		}

	}

}
