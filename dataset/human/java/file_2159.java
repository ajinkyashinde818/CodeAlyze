import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {
	public static void main (String args[]) throws Exception{
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		int ans = 0;
		Map<Long, Integer> map = new HashMap<Long, Integer>();
		if(n == 1) {
			System.out.println(0);
			return;
		}
		long tempN = n;
		long loop = (long)Math.sqrt(n);
		for(long z = 2; z < loop ; z++) {
			if(tempN % z == 0) {
				tempN = tempN / z;
				map = addValue(map, z);
				z = 1;
			}
		}
		ans = calcPrimeNumber(map);
		if(loop < tempN) {
			ans++;
		}
		System.out.println(ans);
	}
		
	private static Map<Long, Integer> addValue(Map<Long, Integer> map, long z) {
		if(map.get(z) == null) {
			map.put(z, 1);
		} else {
			int sum = map.get(z) + 1;
			map.put(z, sum);
		}
		return map;
	}
	
	private static int calcPrimeNumber(Map<Long, Integer> map) {
		int num = 0;
		for(long key : map.keySet()) {
			int minus = 1;
			int value = map.get(key);
			while (value >= minus) {
				value = value - minus;
				minus++;
				num++;
			}
		}
		return num;
	}
}
