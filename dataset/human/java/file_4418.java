import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入力

		int n = sc.nextInt();


		List<Integer> listA = new ArrayList<>();
		List<Integer> listB = new ArrayList<>();
		List<Integer> listC = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			listA.add(a);
		}
		for (int i = 0; i < n; i++) {
			int b = sc.nextInt();
			listB.add(b);
		}
		for (int i = 0; i < n-1 ; i++) {
			int c = sc.nextInt();
			listC.add(c);
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			int a = listA.get(i);
			int b = listB.get(a-1);
			result += b;

			int nextA = i == n-1 ? -1 : listA.get(i+1);
			if(nextA == a + 1 ){
				int c = listC.get(a-1);
				result += c;
			}
		}

		System.out.println(result);


	}
}
