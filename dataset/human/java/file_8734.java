import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int ans = 0;
		int count = 0;
		for(int i = Math.min(A,B); i >= 1; i--) {
			if(A % i == 0 && B % i==0) {
				count++;	
				ans = i;
				if(count == K) {
					break;
				}
			}
		}
		System.out.print(ans);
	}
}
