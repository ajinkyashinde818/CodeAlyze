import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static final long DEV_NUM = 1000000000 + 7;
	
	public void solve() {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		String S = in.next();
		in.close();
		
		int[] alpha = new int[26];
		Arrays.fill(alpha, 0);
		for (int i=0; i<N; i++) {
			alpha[S.charAt(i)-'a']++;
		}
		
		long total = 1;
		for (int i=0; i<alpha.length; i++) {
			total = (total * (alpha[i]+1)) % DEV_NUM;
		}
		
		total = (total - 1 + DEV_NUM) % DEV_NUM;
		
		System.out.println(total);
		
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}
}
