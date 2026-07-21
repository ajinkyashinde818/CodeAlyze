import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;

public class Main {
	static List<Long> primList = new ArrayList<Long>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		read();
	}

	public static boolean isPrime(long N) {
		if (N <= 1) {
			return false;
		}
		long t = (long) Math.sqrt(N);
		for (long i = 2; i <= t; i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}

	public static void init() {
		for (long i = 2; i <= 1000000; i++) {
			if (isPrime(i)) {
				primList.add(i);
			}
		}
	}

	public static void fenjie(long n) {
		int index = 0;
		long t = primList.get(index);
		HashMap<Long, Integer> map = new HashMap<>();
		while (n != 1 && index < primList.size()) {
			t = primList.get(index);
			if (n % t == 0) {
				Integer v = map.get(t);
				if (v == null) {
					map.put(t, 1);
				} else {
					map.put(t, v + 1);
				}
				n = n / t;
			} else {
				index++;
			}
		}
		if (n != 1) {
			map.put(n, 1);
		}
		long res = 0;
		for (Entry<Long, Integer> entry : map.entrySet()) {
			long v = entry.getValue();
			t = (long)Math.sqrt(2*v);
			if( t*(t+1) > 2*v) {
				res += t-1;
			}else{
				res += t;
			}
		}
		System.out.println(res);
		
	}

	private static void read() throws IOException {
		init();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		long n = Long.valueOf(str);
		fenjie(n);

		br.close();

	}

}
