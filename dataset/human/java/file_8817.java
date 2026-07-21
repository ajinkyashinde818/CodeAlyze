import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		List<Integer> k = new ArrayList<Integer>();
		for (int i=1; i<= Math.min(A, B); i++) {
			if ((A%i == 0) && (B%i == 0)) {
				k.add(i);
			}
		}

		Collections.sort(k, Collections.reverseOrder());

		System.out.println(k.get(K-1));
	}
}
