import java.util.*;

public class Main {
    static class UnionFind {
        List<Integer> Parent;
        UnionFind(int N) {
            Parent = new ArrayList<Integer>();
            Integer[] values = new Integer[N];
            Arrays.fill(values, -1);
            Parent.addAll(Arrays.asList(values));
        }
        int root(int A) {
            if (Parent.get(A) < 0)
                return A;
            int root = root(Parent.get(A));
            Parent.set(A, root);
            return root;
        }
        int size(int A) {
            return -Parent.get(root(A));
        }

        boolean connect(int A, int B) {
            A = root(A);
            B = root(B);
            if (A == B) {
                return false;
            }

            if (size(A) < size(B)) {
                int temp = A;
                A = B;
                B = temp;
            }

            Parent.set(A, Parent.get(A) + Parent.get(B));
            Parent.set(B, A);

            return true;
        }
    }
    static class Pair{
        public int x;
        public int y;
        public Pair(int x,int y) {
            this.x=x;
            this.y=y;
        }
        @Override
        public boolean equals(Object obj) {
            if(obj instanceof Pair) {
                Pair other = (Pair) obj;
                return other.x==this.x && other.y==this.y;
            }
            return false;
        }//同値の定義
        @Override
        public int hashCode() {
            return Objects.hash(this.x,this.y);
        }//これ書かないと正しく動作しない（要　勉強）
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int K = Integer.parseInt(sc.next());
        int L = Integer.parseInt(sc.next());
        UnionFind road = new UnionFind(N);
        for (int i=0;i<K;i++) {
            int p = Integer.parseInt(sc.next())-1;
            int q = Integer.parseInt(sc.next())-1;
            road.connect(p, q);
        }

        UnionFind train = new UnionFind(N);
        for (int i=0;i<L;i++) {
            int r = Integer.parseInt(sc.next())-1;
            int s = Integer.parseInt(sc.next())-1;
            train.connect(r, s);
        }

        HashMap<Pair, Integer> map = new HashMap<Pair, Integer>();
        for (int i=0;i<N;i++) {
            int road_r = road.root(i);
            int train_r = train.root(i);
            Pair pair = new Pair(road_r, train_r);
            if (map.containsKey(pair)) {
                map.put(pair, map.get(pair)+1);
            } else {
                map.put(pair, 1);
            }
        }

        for (int i=0;i<N;i++) {
            int road_r = road.root(i);
            int train_r = train.root(i);
            Pair pair = new Pair(road_r, train_r);
            System.out.println(map.get(pair));
        }
    }
}
