import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int count = 0;
		int ans = 0;
		for(int i = 100; i > 0; i--) {
			if((A % i == 0) && (B % i == 0)) {
				count++;
			}
			if(count == K) {
				ans = i;
				break;
			}
		}
		System.out.println(ans);
	}

}
