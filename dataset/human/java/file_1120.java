import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] s = new long[N];
		long a1 = sc.nextLong();
		long total = a1;
		s[0] = a1;
		for(int i = 1; i < N; i++) {
			long a = sc.nextLong();
			s[i] = s[i-1] + a;
			total += a;
		}
		long ans = Long.MAX_VALUE;
		for(int i = 0; i < N-1; i++)
			ans = Math.min(ans, Math.abs(total-2*s[i]));
		System.out.println(ans);
	}

}
