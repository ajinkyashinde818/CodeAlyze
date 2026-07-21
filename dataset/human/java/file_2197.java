import java.util.*;

public class Main{

    private static long max;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        Map<Long, Integer> map = primeFactorization(n);
        int count = 0;

        for(long l : map.keySet()){
            for(int i = 1; map.get(l) >= i; i++){
                map.put(l, map.get(l) - i);
                count++;
            }
        }
        System.out.println(count);
    }

    static boolean isPrime(long n){
        if(n == 2){
            return true;
        }
        if(n < 2 || n % 2 == 0){
            return false;
        }
        long sqrt = (long)Math.sqrt(n);
        for(long i = 3; i <= sqrt; i += 2){
            if(n % i == 0){
                return false;
            }

        }
        return true;
    }

    static Map<Long, Integer> primeFactorization(long n){
        Map<Long, Integer> result = new TreeMap<>();
        if(isPrime(n)){
            result.put(n, 1);
            return result;
        }
        for(long i = 2; i * i <= n; i++){
            if(n % i != 0){
                continue;
            }
            int p = 0;
            while(n % i == 0){
                p++;
                n /= i;
            }
            result.put(i, p);
        }
        if(n != 1){
            result.put(n, 1);
        }
        return result;
    }

}
