import java.util.*;

public class Main {

    private static int N;
    private static int K;
    private static int L;
    private static int[] P;
    private static int[] Q;
    private static int[] R;
    private static int[] S;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        L = sc.nextInt();
        P = new int[K];
        Q = new int[K];
        for (int i = 0; i < K; i++) {
            P[i] = sc.nextInt();
            Q[i] = sc.nextInt();
        }
        R = new int[L];
        S = new int[L];
        for (int i = 0; i < L; i++) {
            R[i] = sc.nextInt();
            S[i] = sc.nextInt();
        }
        System.out.println( solve() );
    }

    private static String solve() {
        UnionFind roads = new UnionFind(N);
        for (int i = 0; i < K; i++) {
            if( P[i] < Q[i] ) {
                roads.unite(P[i]-1, Q[i]-1);
            } else {
                roads.unite(Q[i]-1, P[i]-1);
            }
        }

        UnionFind rails = new UnionFind(N);
        for (int i = 0; i < L; i++) {
            if( R[i] < S[i] ) {
                rails.unite(R[i]-1, S[i]-1);
            } else {
                rails.unite(R[i]-1, S[i]-1);
            }
        }

        Map<Group, Integer> groupCounts = new HashMap<>();
        for (int i = 0; i < N; i++) {
            Group g = new Group(roads.root(i), rails.root(i));
            if( groupCounts.containsKey(g) ) {
                groupCounts.put(g, groupCounts.get(g) + 1);
            } else {
                groupCounts.put(g, 1);
            }
        }

        StringJoiner ans = new StringJoiner(" ");
        for (int i = 0; i < N; i++) {
            Group g = new Group(roads.root(i), rails.root(i));
            ans.add( String.valueOf(groupCounts.get(g)) );
        }
        return ans.toString();
    }

    private static class Group {
        private final int road;
        private final int rail;

        public Group(int road, int rail) {
            this.road = road;
            this.rail = rail;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Group group = (Group) o;
            return road == group.road &&
                    rail == group.rail;
        }

        @Override
        public int hashCode() {

            return Objects.hash(road, rail);
        }
    }

    static class UnionFind {

        private final int[] parent;
        private final int[] rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int root(int i) {
            if( parent[i] == i ) {
                return i;
            } else {
                return parent[i] = root(parent[i]);
            }
        }

        public void unite(int i, int j) {
            int ri = root(i);
            int rj = root(j);
            if( ri == rj ) return;

            if( rank[ri] < rank[rj] ) {
                parent[ri] = rj;

            } else {
                parent[rj] = ri;
                if( rank[ri] == rank[rj] ) {
                    rank[ri]++;
                }
            }
        }

        public boolean isSame(int a, int b) {
            return root(a) == root(b);
        }
    }
}
