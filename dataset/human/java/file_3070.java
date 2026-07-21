import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		HashSet<Integer> set = new HashSet<>();
		int n = sc.nextInt();
		int m = sc.nextInt();
		for (int i = 0; i < m; i++) {
		    int a = sc.nextInt();
		    int b = sc.nextInt();
		    if (a == 1) {
		        if (set.contains(b)) {
		            System.out.println("POSSIBLE");
		            return;
		        }
		        set.add(b);
		    }
		    if (b == n) {
		        if (set.contains(a)) {
		            System.out.println("POSSIBLE");
		            return;
		        }
		        set.add(a);
		    }
		}
		System.out.println("IMPOSSIBLE");
	}
}
