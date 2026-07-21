import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(System.in);
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    long mod = 1000000000+7;

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        main.solve();
//        out.println(main.solve());
        out.flush();
    }
    void solve() throws IOException {
        long n =sc.nextLong();
        Map<Long, Integer> map = new HashMap<>();
        for(long p=2; p*p<=n; p++){
            if(n%p!=0) continue;
            int cnt = 0;
            while(n%p==0){
                cnt++;
                n = n/p;
            }
            map.put(p,cnt);
        }
        if(n>1) map.put(n,1);
        long ans = 0;
        for(long key:map.keySet()){
            int val = map.get(key);
            ans += helper(val);
        }
        out.println(ans);
    }
    int helper(int n){
        int ans = 0, i = 1;
        while(n>0){
            if(n>=i) ans++;
            n -= i;
            i++;
        }
        return ans;
    }
}
