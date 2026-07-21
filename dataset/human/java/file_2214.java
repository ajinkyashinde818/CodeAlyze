import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		Map <Long,Long>  map = new HashMap<Long,Long>();
		long i=2;
		boolean b = false;
		while(i*i<=N) {
			while (N%i==0) {
				b =true;
				if (map.get(i)==null) {
					map.put(i,1l);
				} else {
					long temp = map.get(i);
					map.put(i, temp+1l);
				}
				N/=i;
			}
			i++;
		}
		if (N>1) {
			map.put(N, 1l);
		}
		if (N>1&&b==false) {
			System.out.println(1);
			return ;
		}
		long sum =0;
		Set<Long> set = map.keySet();
		for (long l: set) {
			long temp = map.get(l);
			i=1;
			while (temp>=i) {
				sum ++;
				temp -=i;
				i++;
			}
		}
		System.out.println(sum);
	}
}
