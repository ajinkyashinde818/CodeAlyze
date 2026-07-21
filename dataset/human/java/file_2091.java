import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		int ans = 0;
		Map<Long, Integer> fact = new HashMap<>();
		for(long i = 2; i <= Math.sqrt(N); i++) {
			if(N % i == 0) {
				int n = 0;
				while(N % i == 0) {
					N /= i;
					n++;
				}
				fact.put(i, n);
			}
		}
		if(N > 1)
			fact.put(N, 1);
		for(int i : fact.values()) {
			int x = 1;
			while(i >= x) {
				i -= x;
				x++;
				ans++;
			}
		}
		System.out.println(ans);
	}

}
