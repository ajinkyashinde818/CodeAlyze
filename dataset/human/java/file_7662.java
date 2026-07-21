import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N];
		Arrays.setAll(A, i -> sc.nextInt());
		Set<Integer> used = new HashSet<>();
		used.add(1);
		int prev = 1;
		List<Integer> l = new ArrayList<>();
		l.add(1);
		while(true) {
			if(used.contains(A[prev-1]))
				break;
			used.add(A[prev-1]);
			l.add(A[prev-1]);
			prev = A[prev-1];
		}
		int index = l.indexOf(A[prev-1]);
		if(K <= index)
			System.out.println(l.get((int)K));
		else
			System.out.println(l.get((int)(index + (K-index) % (l.size()-index))));
	}

}
