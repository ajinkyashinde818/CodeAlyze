import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        Map<Integer, Integer> h = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int x = Integer.parseInt(sc.next());
            int y = Integer.parseInt(sc.next());
            if (x == 1) {
                if (h.containsKey(y)) {
                    h.put(y, h.get(y) + 1);
                } else {
                    h.put(y, 1);
                }
            } else if (y == n) {
                if (h.containsKey(x)) {
                    h.put(x, h.get(x) + 1);
                } else {
                    h.put(x, 1);
                }
            }
        }
        sc.close();
        for (int v : h.values()) {
            if (v == 2) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
