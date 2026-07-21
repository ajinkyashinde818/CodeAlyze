import java.util.*;

public class Main {

    static int solve(int n, long k, int[] A) {
        int p = 0;
        List<Integer> l = new ArrayList<>();
        Map<Integer, Integer> used = new HashMap<>();
        while (!used.containsKey(p)) {
            used.put(p, l.size());
            l.add(p);
            p = A[p];
        }

        int loop = l.size() - used.get(p);

        if (k < used.get(p)) return l.get((int)k) + 1;
        k -= used.get(p);
        k %= loop;
        return l.get((int)(used.get(p) + k)) + 1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long k = in.nextLong();
        int[] A = new int[n];
        for (int i=0;i<n;i++) A[i] = in.nextInt() - 1;
        System.out.println(solve(n, k, A));
    }
}
