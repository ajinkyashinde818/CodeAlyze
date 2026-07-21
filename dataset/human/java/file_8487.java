import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        int K = scan.nextInt();
        int L = scan.nextInt();
        UnionFind road = new UnionFind(N);
        UnionFind train = new UnionFind(N);
        for (int i = 0; i < K; i++) {
            int p = scan.nextInt() - 1;
            int q = scan.nextInt() - 1;
            road.merge(p, q);
        }
        for (int i = 0; i < L; i++) {
            int p = scan.nextInt() - 1;
            int q = scan.nextInt() - 1;
            train.merge(p, q);
        }
        Map<Long, Integer> count = new HashMap<>();
        for (int i = 0; i < N; i++) {
            long r_p = road.parent(i);
            long t_p = train.parent(i);
            long key = r_p * 1000000 + t_p;
            count.merge(key, 1, Integer::sum);
        }
        int[] answers = new int[N];
        for (int i = 0; i < N; i++) {
            long r_p = road.parent(i);
            long t_p = train.parent(i);
            long key = r_p * 1000000 + t_p;
            answers[i] = count.get(key);
        }
        System.out.println(Arrays.stream(answers).mapToObj(i -> Integer.toString(i)).collect(Collectors.joining(" ")));
    }
    class UnionFind {
        private int[] par;
        private int[] size;
        UnionFind(int N) {
            this.par = new int[N];
            for (int i = 0; i < N; i++) {
                par[i] = i;
            }
            this.size = new int[N];
            for (int i = 0; i < N; i++) {
                this.size[i] = 1;
            }
        }
        int parent(int N) {
            if (this.par[N] == N) {
                return N;
            }
            return this.par[N] = parent(this.par[N]);
        }
        boolean same(int x, int y) {
            int parent_x = parent(x);
            int parent_y = parent(y);
            return parent_x == parent_y;
        }
        void merge(int x, int y) {
            int parent_x = parent(x);
            int parent_y = parent(y);
            if (parent_x == parent_y) {
                return;
            }
            int size_x = this.size[parent_x];
            int size_y = this.size[parent_y];
            if (size_x < size_y) {
                this.par[parent_x] = parent_y;
                this.size[parent_y] += this.size[parent_x];
                this.size[parent_x] = -1;
                return;
            }
            this.par[parent_y] = parent_x;
            this.size[parent_x] += this.size[parent_y];
            this.size[parent_y] = -1;
        }
    }
}
