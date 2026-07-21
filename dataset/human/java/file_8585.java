import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		int a = scn.nextInt();
		int b = scn.nextInt();
		int k = scn.nextInt();

		ArrayList<Integer> list = new ArrayList<>();

		int i = 1;
		do {
			if (a % i == 0 && b % i == 0) {
				list.add(i);
			}
			i++;
		} while (i <= a);

		System.out.println(list.get((list.size()-k)));
	}
}
