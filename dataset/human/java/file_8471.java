import java.util.HashMap;
import java.util.Objects;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int K = scanner.nextInt();
    int L = scanner.nextInt();

    UnionFind ufk = new UnionFind(N);
    UnionFind ufl = new UnionFind(N);
    for (int i = 0; i < K; i++) {
      int p = scanner.nextInt() - 1;
      int q = scanner.nextInt() - 1;
      ufk.union(p, q);
    }

    for (int i = 0; i < L; i++) {
      int p = scanner.nextInt() - 1;
      int q = scanner.nextInt() - 1;
      ufl.union(p, q);
    }

    HashMap<Pair, Integer> count = new HashMap<>();
    for (int i = 0; i < N; i++) {
      Pair p = new Pair(ufk.find(i), ufl.find(i));
      count.put(p, count.getOrDefault(p, 0) + 1);
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < N; i++) sb.append(count.get(new Pair(ufk.find(i), ufl.find(i)))).append(' ');
    System.out.println(sb.toString());
  }

  static class Pair {
    public final int k;
    public final int l;

    Pair(int k, int l) {
      this.k = k;
      this.l = l;
    }

    @Override public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;
      Pair pair = (Pair) o;
      return k == pair.k &&
          l == pair.l;
    }

    @Override public int hashCode() {
      return Objects.hash(k, l);
    }
  }

  static class UnionFind {
    private final int[] table;
    private final int[] ranks;
    private final int[] sizes;

    public UnionFind(int size) {
      this.table = new int[size];
      this.ranks = new int[size];
      this.sizes = new int[size];
      for (int i = 0; i < size; i++) {
        table[i] = i;
        sizes[i] = 1;
      }
    }

    public int find(int x) {
      if (table[x] != x) {
        table[x] = find(table[x]);
      }
      return table[x];
    }

    public void union(int x, int y) {
      int xRoot = find(x);
      int yRoot = find(y);
      if (xRoot == yRoot) return;

      if (ranks[xRoot] < ranks[yRoot]) {
        int tmp = xRoot;
        xRoot = yRoot;
        yRoot = tmp;
      }

      table[yRoot] = xRoot;
      sizes[xRoot] += sizes[yRoot];
      if (ranks[xRoot] == ranks[yRoot]) ranks[xRoot]++;
    }
  }
}
