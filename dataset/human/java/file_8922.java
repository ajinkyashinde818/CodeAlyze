import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		ArrayList<Integer> array = new ArrayList<Integer>();
		for (int i = 1; i <= 100; i++) {
			if (a % i == 0 && b % i == 0) {
				array.add(i);
			}
		}
		System.out.println(array.get((array.size() - c)));
	}

}
