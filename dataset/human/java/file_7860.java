import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        long k = Long.parseLong(sc.next());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next()) - 1;
        }
        Set<Integer> set = new HashSet<>();
        int idx = 0;
        int loopIdx = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (set.contains(idx)) {
                loopIdx = list.indexOf(idx);
                break;
            } else {
                set.add(idx);
                list.add(idx);
                idx = a[idx];
            }
        }
        if (list.size() > k) {
            System.out.println(list.get((int)k) + 1);
        } else {
            int ans = 0;
            ans = (int)((k - loopIdx) % (list.size() - loopIdx));
            System.out.println(list.get(loopIdx + ans) + 1);
        }
    }
}
