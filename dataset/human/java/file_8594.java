import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		sc.close();
		int min = Math.min(A, B);
		List<Integer> list = new ArrayList<Integer>();
		for(int i = 1; i <= min; i++) {
			if(A % i == 0 && B % i == 0) {
				list.add(i);
			}
		}
		Collections.sort(list, Collections.reverseOrder());
		System.out.println(list.get(K - 1));
	}
}
