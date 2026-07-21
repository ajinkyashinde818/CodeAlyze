import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();

		int B = sc.nextInt();

		int C = sc.nextInt();

		int D = A+B;

		int ans = B;

		if(C<=D) {

			ans += C;

		}else {

			ans += D+1;
		}

		System.out.println(ans);
	}

}
