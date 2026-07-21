import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt();
		int n,m,gcd,reminder;
		n = Math.min(a, b);
		m = Math.max(a, b);
		while(true) {
			if( m % n != 0) {
				reminder = m % n;
				m = n;
				n = reminder;
			}else {
				gcd = n;
				break;
			}
		}
		
		System.out.println((long)a * (long)b / (long)gcd);
	}
}
