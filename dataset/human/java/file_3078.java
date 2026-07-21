import java.util.HashSet;
import java.util.Scanner;

public class Main {

	private static final String POSSIBLE = "POSSIBLE";
	private static final String IMPOSSSIBLE = "IMPOSSIBLE";

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int M = sc.nextInt();
		HashSet<Integer> fromOne = new HashSet<>();
		HashSet<Integer> toN = new HashSet<>();
		
		for (int i=0; i<M; i++) {
			int ai = sc.nextInt();
			int bi = sc.nextInt();
			if(ai ==1) {
				fromOne.add(bi);
			}
			if(bi == N) {
				toN.add(ai);
			}
		}
		
		sc.close();
		
		for(Integer n: fromOne) {
			if(toN.contains(n)) {
				System.out.println(POSSIBLE);
				return;
			}
		}
		System.out.println(IMPOSSSIBLE);
	}

}
