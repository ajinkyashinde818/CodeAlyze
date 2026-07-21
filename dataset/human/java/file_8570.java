import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int n = Math.min(a, b);
		int ans = 0;
		sc.close();
		
		for(int i = n; i >= 1; i--){
			if(a % i == 0 && b % i == 0) {
				k--;
				ans = i;
				
				if(k == 0) {
					break;
				}
			}
		}
		System.out.println(ans);
	}
}
