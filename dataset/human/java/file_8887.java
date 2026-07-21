import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {
			int A = Integer.parseInt(sc.next());
			int B = Integer.parseInt(sc.next());
			int K = Integer.parseInt(sc.next());
			List<Integer> l = new ArrayList<Integer>();
			for(int i = 1; i <= Math.min(A, B); i++) {
				if(A % i == 0 && B % i == 0) {
					l.add(0, i);
				}
			}
			System.out.println(l.get(K - 1));
		} // Scanner Close
	}
}
