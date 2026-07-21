import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int mod = 1000000007;
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Integer v = map.get(s.charAt(i));
            if (v == null) {
                map.put(s.charAt(i), 2);
            } else {
                map.put(s.charAt(i), ++v);
            }
        }
        long ans = 1;
        for (Character key : map.keySet()
             ) {
            ans *= map.get(key);
            ans %= mod;
        }

        System.out.println(--ans);
    }
}
