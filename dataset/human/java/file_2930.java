import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        PriorityQueue<Integer> sKouho = new PriorityQueue<>();
        HashSet<Integer> eKouho = new HashSet<>();

        for (int i = 0; i < m; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            if (s == 1) {
                sKouho.add(e);
            } else if (e == n) {
                eKouho.add(s);
            }
        }

        String ans = "IMPOSSIBLE";

        int count = sKouho.size();
        int eCount = eKouho.size();

        for (int i = 0; i < count; i++) {
            eKouho.add(sKouho.poll());
            if (eCount == eKouho.size()) {
                ans = "POSSIBLE";
                break;
            } else {
                eCount++;
            }
        }

        System.out.println(ans);
    }
}
