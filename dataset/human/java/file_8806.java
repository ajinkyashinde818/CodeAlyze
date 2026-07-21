import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		int a, b, k;
		ArrayList<Integer> list = new ArrayList<>();
		
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		k = scanner.nextInt();
		
		scanner.close();
		
		int max = Math.max(a,  b);
		
		for (int i = 1; i <= max; i++) {
			if (a % i == 0 && b % i == 0) {
				list.add(0, i);
			}
		}
		
		System.out.println(list.get(k-1));
	}

}
