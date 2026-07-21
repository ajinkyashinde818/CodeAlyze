import java.util.*;
public class Main {
	
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		Set<Integer> start = new HashSet<>();
		Set<Integer> end = new HashSet<>();
		for (int i = 0; i < M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			if (a == 1) {
				start.add(b);
			}
			
			if (b == N) {
				end.add(a);
			}
		}
		
		for (Integer a: start) {
			if (end.contains(a)) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		
		System.out.println("IMPOSSIBLE");
	}
	
}
