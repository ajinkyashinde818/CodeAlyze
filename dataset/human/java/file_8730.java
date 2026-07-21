import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Long A = Long.parseLong(sc.next());
		Long B = Long.parseLong(sc.next());
		int K = Integer.parseInt(sc.next());
		sc.close();
		ArrayList<Integer> list = new ArrayList<Integer>();

		for(int i = 1; i <= 100 ; i++) {
			if(A % i == 0 && B % i == 0) {
				list.add(i);
			}
		}
		Collections.sort(list, Collections.reverseOrder());
		System.out.println(list.get(K - 1));
	}
}
