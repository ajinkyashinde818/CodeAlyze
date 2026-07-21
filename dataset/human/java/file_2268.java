import java.util.*;

public class Main {
    Scanner sc = new Scanner(System.in);

    void run() {
        int n = ni();
        ArrayList<LinkedList<Integer>> list = new ArrayList<>();
        for (int i = 0; i <= 100001; ++i) {
            list.add(new LinkedList<>());
        }
        for (int i = 0; i < n; ++i) {
            int a = ni();
            int b = ni();
            list.get(a).add(b);
        }
        int max = 0;
        PriorityQueue<Integer> kouho = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> friends = new PriorityQueue<>();
        for (int i = 2; i <= 100001; ++i) {
            kouho.addAll(list.get(i));
            while (friends.size() < i - 1 && kouho.size() > 0) {
                int v = kouho.poll();
                if (v < i) {
                    break;
                }
//                if (i <= 10)
//                    debug(i, "add", v);
                friends.add(v);
            }
            if (friends.size() == i - 1) {
                max = Math.max(max, i - 1);
            }
            while (friends.size() > 0 && friends.peek() == i) {
                int v = friends.poll();
//                if (i <= 10) debug(i, "remove", v);
            }
//            if (i <= 10) debug(i, friends);
        }
        System.out.println(max);
    }

    int ni() {
        return Integer.parseInt(sc.next());
    }

    public static void main(String[] args) {
        new Main().run();
    }

    void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
