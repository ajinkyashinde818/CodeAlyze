import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		if(A + B + 1 >= C) {
			System.out.println(B + C);
		}else {
			long ans = A + 2 * B + 1;
			System.out.println(ans);
		}
	}
}
