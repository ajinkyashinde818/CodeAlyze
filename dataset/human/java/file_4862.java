import java.util.Scanner;

public class Main {
	static long[] pow5;
	static{
		pow5 = new long[26];
		long p = 1;
		for(int i = 0; i < 26; i++){
			pow5[i] = p;
			p *= 5;
		}
	}
	public static void main(String[] args) {
		final int maxNum = 18;
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long ans = 0;
		for(int i = 1; i < 26; i++){
			ans += n / 2 / pow5[i];
		}
		System.out.println(n % 2 == 0 ? ans : 0);
	}
}
