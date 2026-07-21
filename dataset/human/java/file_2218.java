import java.math.BigInteger;
import java.util.*;

public class Main {
    static final Map<Long, Integer> primes = new HashMap<>();

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        while(N>1) {
            if(N%2L!=0L) break;
            add(2L);
            N/=2L;
            continue;
        }
        long div = 3L;
        while(N>1 && div*div<=N) {
            if(N%div!=0L) {
                div+=2L;
                continue;
            }
            add(div);
            N/=div;
        }
        if(N>1) {
            add(N);
        }
//        for(long key : primes.keySet()) {
//            System.out.println(String.format("%d:%d", key, primes.get(key)));
//        }
        int count = 0;
        for(long key: primes.keySet()) {
            int c = primes.get(key);
            int t = 1;
            while(c>=t) {
                count++;
                c-=t;
                t++;
            }
        }
        System.out.println(count);
    }

    static void add(long t) {
        if(primes.containsKey(t)) {
            int pow = primes.get(t);
            primes.put(t, pow+1);
        } else {
            primes.put(t, 1);
        }
    }
}
