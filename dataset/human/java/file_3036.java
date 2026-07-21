import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        Map<Integer, List<Integer>> routes = new HashMap<>();
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            List<Integer> to = new ArrayList<>();
            if (routes.containsKey(a)) {
                to = routes.get(a);
            }
            to.add(b);

            routes.put(a, to);
        }

        List<Integer> src1Routes = routes.get(1);
        for (int to : src1Routes) {
            if (routes.containsKey(to)) {
                if (routes.get(to).contains(N)) {
                    out.println("POSSIBLE");
                    return;
                }
            }
        }

        out.println("IMPOSSIBLE");
    }
}
