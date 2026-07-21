import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        Map<Long, Integer> map = new HashMap<>();
        long tmp = N;
        for (long i = 2; i*i <= N; i++) {
            while (tmp%i == 0) {
                map.put(i,map.getOrDefault(i,0)+1);
                tmp /= i;
            }
        }
        if (tmp != 1) {
            map.put(tmp,1);
        }

        int ans = 0;
        for (int value : map.values()) {
            int x = 1;
            while (x*(x+1) <= value*2) {
                ans++;
                x++;
            }
        }

        System.out.println(ans);
    }
}
