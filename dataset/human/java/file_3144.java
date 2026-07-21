import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//String s = sc.next();
		long n = sc.nextLong();
		//long m = sc.nextLong();

		if(n/10==9||n%10==9) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		//System.out.println((n-1)*(m-1));
	}
}
