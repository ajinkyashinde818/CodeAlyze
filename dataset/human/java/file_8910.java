import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int A = scan.nextInt();
		int B = scan.nextInt();
		int K = scan.nextInt();
		int cnt = 0;
		int ans = 1;
		
		for (int i = 100; i > 0; i--) {
			if (cnt < K) {
				if (A % i == 0 && B % i == 0) {
					cnt += 1;
					ans = i;
					//System.out.println("cnt" + cnt);
					//System.out.println("ans" + ans);
				}else {
					//System.out.println("no");
				}
			}else {
				break;
			}
		}
		System.out.println(ans);
	}
}
