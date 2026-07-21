import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        long k = Long.parseLong(sc.next());
        int[] a = new int[n+1];
        
        for(int i=1; i<=n; i++) {
            a[i] = Integer.parseInt(sc.next());
        }
        if(k <= n) {
            int x = 1;
            for(int i=0; i<k; i++) {
                x = a[x];
            }
            System.out.println(x);
        }else {
            int x = 1;
            Map<Integer, Integer> map = new HashMap<>();
            int start = 0;
            int finish = 0;
            map.put(1, 0);
            int j = 1;
            while(true) {
                x = a[x];
                if(map.containsKey(x)) {
                    start = map.get(x);
                    finish = j-1;
                    break;
                }else {
                    map.put(x, j);
                }
                j++;
            }
            
            long amari = (k - start + 1) % (finish - start + 1);
            int ans = x;
            if(amari == 0) {
                amari = finish - start + 1;
            }
            for(int i=1; i<amari; i++) {
                ans = a[ans];
            }
        
            System.out.println(ans);
        }
    }
}
