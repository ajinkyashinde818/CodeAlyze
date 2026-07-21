import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		long K = scan.nextLong();
		int[] A = new int[N+1];
		boolean[] vst = new boolean[N+1];
		for (int i = 1; i < N+1; i++) {
			A[i] = scan.nextInt();
		}
		ArrayList<Integer> l = new ArrayList<>();
		int town = 1;

		while (vst[town] == false) {
			vst[town] = true;
			l.add(town);
			town = A[town];
		}

		int s = l.indexOf(town);

		if (K < s+1) {
		} else {
			K -= s;
			for (int i = 0; i < s; i++) {
				l.remove(0);
			}
			K %= l.size();
		}

		System.out.println(l.get((int)K));

	}
}
