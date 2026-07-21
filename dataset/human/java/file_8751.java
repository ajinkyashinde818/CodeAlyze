import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt(), k = sc.nextInt();
		sc.close();
		int ans = 0, order = 0;
		
		for(int i = Math.max(a,  b); i >= 1; --i) {
			if(a % i == 0 && b  % i == 0) {
				++order;
				if(order == k)ans = i;
			}
		}
		System.out.println(ans);
	}

}
