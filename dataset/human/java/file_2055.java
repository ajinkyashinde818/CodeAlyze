import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
    static final int MOD = 1000000007;
    static final int INF = 1 << 30;
    static final int ALF = 26;

    Main() {
        Scanner sc = new Scanner(System.in);
        long ans = 0;
        long N = sc.nextLong();
        HashMap<Long,Integer> prime = primeFactor(N);
        
        for(long key:prime.keySet()){
            if(prime.get(key)>0){
                long val = prime.get(key);
                int ck = 1;
                while(val>=ck){
                    val-=ck;
                    ck++;
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        new Main();
    }

    
    public static HashMap<Long,Integer> primeFactor(long n) {
        final HashMap<Long,Integer> list = new HashMap<Long,Integer>();
        if (n < 2) {
            return list;
        }

        int two=0;
        while (n != 1 && n % 2 == 0) {
            //list.put(2l, list.getOrDefault(2l, 0)+1);// add(2l);
            two++;
            n >>>= 1;
        }
        list.put(2l,two);

        for (long i = 3; i * i <= n; i += 2) {
            if(n%i==0){
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                list.put(i,cnt);
            }
        }

        if (n != 1) {
            list.put(n,1);
        }
        return list;
    }

}
