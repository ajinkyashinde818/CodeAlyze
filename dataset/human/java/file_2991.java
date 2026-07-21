import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int[] a = new int[M];
		int[] b = new int[M];
		List<Integer> list = new ArrayList<Integer>();
		boolean possible = false;
		for(int i = 0; i < M; i++) {
			a[i] = scan.nextInt();
			b[i] = scan.nextInt();
			if(a[i] == 1) {
				list.add(b[i]);
			}
			if(b[i] == N) {
				list.add(a[i]);
			}
		}
		List<Integer> hashList = new ArrayList<Integer>(new LinkedHashSet<>(list));

		if(list.size() == hashList.size()) {
			possible = false;
		} else {
			possible = true;
		}
		System.out.println(possible ? "POSSIBLE" : "IMPOSSIBLE");
		scan.close();

	}

}
