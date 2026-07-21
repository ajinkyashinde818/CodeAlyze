import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		ArrayList<Integer> ary = new ArrayList<Integer>();

		for (int i = 1; i < 101; i++) {
			if (A % i == 0 && B % i == 0) {
				ary.add(i);
			}
		}

		System.out.println(ary.get(ary.size() - K));

	}
}
