import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static final int MOD = (int) (Math.pow(10, 9) + 7);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int a = Integer.parseInt(sc.next());
            int b = Integer.parseInt(sc.next());
            if (map.containsKey(a)) {
                map.get(a).add(b);
            } else {
                Set<Integer> set = new HashSet<>();
                set.add(b);
                map.put(a, set);
            }
        }
        if (!map.containsKey(1)) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        Set<Integer> nset = map.get(1);
        for (int a : nset) {
            Set<Integer> aset = map.get(a);
            if (aset != null && aset.contains(n)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
