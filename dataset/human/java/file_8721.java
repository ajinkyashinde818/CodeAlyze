import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(), B = sc.nextInt(), K = sc.nextInt();
		int ans = 0;
		for(int i = Math.min(A, B); i >= 0; i--) {
			if(A % i == 0 && B % i == 0) {
				K--;
				if(K == 0) {
					ans = i;
					break;
				}
			}
		}
		System.out.println(ans);
	}
}
