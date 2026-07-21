import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long num = 0L;
		String s = "";
		HashMap<Long, Long> map = new HashMap<>();
		if(n <= 1) {
			System.out.println(0); //1以下の場合
		return;
		}
		for(long i = 2 ; i <= Math.sqrt(n) ; i++) {
			if(n % i != 0)
				continue;
			n /= i;
			map.put(i, map.getOrDefault(i,  0L) + 1L);
			s += i;
			if(n == 1)
				break;
			s += " * ";
          i--;
		}
      if(n != 1) {
        s += n;
        map.put(n, map.getOrDefault(n,  0L) + 1L);
        }
      for(long i : map.keySet()) {
    	  long j = 0L;
    	  long t = map.get(i);
    	  for(long k = 1 ; ; k++) {
    		  if(t >= k) {
    			  t -= k;
    			  j++;
    		  }
    		  else
    			  break;
    	  }
    	  num += j;

      }
		System.out.println(num);



	}
	public static long pow(long ml, long a, long b){
    if(b == 1)
      return ml;
      ml *= a;
      b--;
		return b == 0 ? ml : pow(ml , a ,b);
	}

}
