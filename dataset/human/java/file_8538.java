import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		sc = null;
		int m = Math.min(a, b);
		int i;
		int c = 0;
		for(i = m; i > 0; i--) {
			if((a % i == 0) && (b % i == 0)) {
				c++;
				if(c == k) break;
			}
		}
		System.out.println(i);
	}
}
