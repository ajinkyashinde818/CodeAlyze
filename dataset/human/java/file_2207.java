import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		HashMap<Long, Integer> map = new HashMap<>();
		for (long i = 2; i <= Math.sqrt(n); i++) {
		    while (n % i == 0) {
		        if (map.containsKey(i)) {
		            map.put(i, map.get(i) + 1);
		        } else {
		            map.put(i, 1);
		        }
		        n /= i;
		    }
		}
		if (n != 1) {
		    if (map.containsKey(n)) {
		        map.put(n, map.get(n) + 1);
		    } else {
		        map.put(n, 1);
		    }
		}
		int count = 0;
		for (int x : map.values()) {
		    int y = x;
		    for (int i = 1; y > 0; i++) {
		        if (y >= i) {
		            count++;
		            y -= i;
		        } else {
		            break;
		        }
		    }
		}
	    System.out.println(count);
	}
}
