import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = Integer.parseInt(sc.next());
		int N = Integer.parseInt(sc.next());
		ArrayList<Integer> list = new ArrayList<>();
		for(int i = 0; i < N; i++) {
			list.add(Integer.parseInt(sc.next()));
		}
		sc.close();

		Collections.sort(list);
		int distance = Integer.MIN_VALUE;
		for(int i = 1; i < list.size(); i++) {
			int start = list.get(i - 1);
			int end = list.get(i);
			int tmpDistance = end - start;
			distance = Math.max(distance, tmpDistance);
		}
		//始点と終点の差チェック
		distance = Math.max(distance, list.get(0) + (K - list.get(N - 1)));

		int ans = K - distance;
		System.out.println(ans);

	}

}
