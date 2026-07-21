import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        
        var sc = new Scanner(System.in);
        
        long n = Long.parseLong(sc.next());
    
        HashMap<Long, Integer> map = primeFactorization(n);
        int ans = 0;
        for(long l : map.keySet()){
            int i = map.get(l);
            int j = 1;
            while(i >= j){
                ans++;
                i -= j;
                j++;
            }
        }
        System.out.println(ans);
    }
    
    static HashMap<Long, Integer> primeFactorization(long n){
        
        var map = new HashMap<Long, Integer>();
        while(n%2 == 0){
            n /= 2;
            map.put(2L, map.getOrDefault(2L, 0)+1);
        }
        double sqrt = Math.sqrt(n);
        for(long l = 3; l <= sqrt; l += 2){
            while(n%l == 0){
                n /= l;
                map.put(l, map.getOrDefault(l, 0)+1);
            }
        }
        if(n > 1) map.put(n, 1);
        return map;
    }
}
