import java.util.Scanner;


public class Main {
	
	
	public static final long MOD = 1_000_000_007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		String s = sc.next();
		boolean[] isRight = new boolean[n*2];
		
		if (s.charAt(0)=='W') {
			System.out.println(0);
			return;
		} else {
			isRight[0]=false;
		}
		
		for (int i=1;i<2*n;i++) {
			isRight[i]=isRight[i-1]^(s.charAt(i)==s.charAt(i-1));
		}
		

		
		long ans = 1;
		long stock = 0;
		for (int i=0;i<2*n;i++) {
			if (isRight[i]) {
				if (stock <= 0) {
					System.out.println(0);
					return;
				}
				ans = (ans*stock)%MOD;
				stock--;
			} else {
				stock++;
			}
		}
		
		if (stock!=0) {
			System.out.println(0);
			return;
		}
		
		for (int i=1;i<=n;i++) {
			ans = (ans*i)%MOD;
		}
		
		System.out.println(ans);
	}
}
