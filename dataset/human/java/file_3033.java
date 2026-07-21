import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		Set<Integer> c = new HashSet<>();
		Set<Integer> d = new HashSet<>();
		for(int i = 0; i < M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a == 1)
				c.add(b);
			if(b == N)
				d.add(a);
		}
		for(int i : c) {
			if(d.contains(i)) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}

}
