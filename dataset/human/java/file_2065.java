import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long n = sc.nextLong();

        long x = n;
        long ans = 0;

        HashMap<Long, Long>map = new HashMap<Long, Long>();
        for (long i = 2; i <= Math.sqrt(n);) {
            if (x % i == 0) {

            	x /= i;

            	if (map.containsKey(i)){
            		map.put(i, map.get(i)+1);
            	} else {
            		map.put(i, 1L);
            	}

            } else {
            	i++;
            }
        }
        if (x > 1){
        	map.put(x, 1L);
        }

        for (Entry<Long,Long> entry : map.entrySet()){
        	long value = entry.getValue();
        	for (int i=1; value > 0; i++){
        		if (value >= i){
        			ans++;
        		}
        		value -= i;
        	}
        }

        System.out.println(ans);
	}

}
