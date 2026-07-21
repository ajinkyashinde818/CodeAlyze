import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();

        HashSet<Integer> distFromOne = new HashSet<>();
        HashSet<Integer> distToN = new HashSet<>();
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();

            if (from == 1) {
                distFromOne.add(to);
            }
            if (to == N) {
                distToN.add(from);
            }
        }
        for (Integer dist : distFromOne)  {
            if (distToN.contains(dist)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
