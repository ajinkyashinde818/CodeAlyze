import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s  = sc.next().toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0 ; i < n ; i++) {
            if (map.containsKey(s[i])) {
                map.put(s[i], map.get(s[i]) + 1);
            } else {
                map.put(s[i], 1);
            }
        }
        long ans = 1;
        int mod = 1000000007;
        for (Entry<Character, Integer> entry : map.entrySet()) {
            ans *= (entry.getValue()  + 1 ) % mod;
            ans %= mod;
        }
        System.out.println((ans + mod - 1) % mod);
    }


}
