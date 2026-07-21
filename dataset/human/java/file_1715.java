import java.util.Scanner;

public class Main {
	Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}
	
	void run() {
		int n = sc.nextInt();
		char[] s = sc.next().toCharArray();
		int mod = 1_000_000_007;
		
		int count[] = new int[26];

		for(int i = 0 ; i < n ; i ++) {
			count[s[i]- 'a']++;
		}
		long sum = 1;
		for(int i = 0 ;i < 26; i++) {
			sum = (sum  * (count[i]+1)) % mod;
		}
		System.out.println(sum-1);
		
	}
}
