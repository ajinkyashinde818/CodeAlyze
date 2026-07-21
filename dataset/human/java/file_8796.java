import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		List<Integer> list = new ArrayList<Integer>();


		int min = Math.min(A, B);

		int K = sc.nextInt();
		for (int i = 1; i <= min; i++) {

			if (A % i == 0 && B % i == 0) {

				list.add(i);
			}

		}
		Collections.sort(list, Comparator.reverseOrder());
		System.out.println(list.get(K-1));

	}

}
