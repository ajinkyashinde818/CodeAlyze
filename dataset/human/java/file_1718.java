import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String st = sc.next();
		int count[] = new int[26];
		for(int i = 0; i < num; i ++) {
			count[st.charAt(i) - 'a'] ++;
		}
		long ans = 1;
		for(int i = 0; i < 26; i ++) {
			ans = mod(ans * (count[i] + 1));
		}
		ans = mod(ans - 1);
		System.out.println(ans);
	}

	static long divisor = (long)Math.pow(10, 9) + 7;
	public static long mod(long i) {
		return i % divisor + ((i % divisor) < 0 ? divisor : 0);
	}
}
