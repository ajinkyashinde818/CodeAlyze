import java.util.Scanner;

public class Main {
	
	static int mod = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		
		char []s = sc.next().toCharArray();
		
		int[]c = new int [27];
		
		for(int i = 0 ; i < n ; i++) {
			int m = (int)(s[i] - 'a');
			c[m]++;
		}
		
		long ans = 1;
		
		for(int i = 0 ; i < 27 ;i++) {
			int temp = c[i] + 1;
			ans = ans * temp % mod;
		}
		
		System.out.println(ans-1);
		
		

	}
	
}
