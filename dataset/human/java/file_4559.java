import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		if (C<=A+B) {
			System.out.println(C+B);
			return ;
		}
		System.out.println(B+(A+B+1));
	}
}
