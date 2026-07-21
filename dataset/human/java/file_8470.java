import java.util.Scanner;
import java.util.TreeMap;
 
@SuppressWarnings("unchecked")
public class Main {
  class UnionFind {
    int[] parent;
    int[] size;
    int n;

    UnionFind(int n) {
      this.parent = new int[n];
      this.size = new int[n];
      this.n = n;
      for (int i = 0; i < n; i++) {
        this.parent[i] = i;
        this.size[i] = 1;
      }
    }

    void union(int a, int b) {
      int pa = find(a);
      int pb = find(b);

      if (pa == pb) {
        return;
      }

      if (this.size[pa] > this.size[pb]) {
        this.size[pa] += this.size[pb];
        this.parent[pb] = pa;
      } else {
        this.size[pb] += this.size[pa];
        this.parent[pa] = pb;
      }
    }

    int find(int a) {
      if (this.parent[a] == a) {
        return a;
      } else {
        return find(this.parent[a]);
      }
    }

    @Override
    public String toString() {      
      String ret = "";
      for (int i = 0; i < this.n; i++) {
        ret += this.parent[i] + " ";
      }
      ret += '\n';
      for (int i = 0; i < this.n; i++) {
        ret += this.size[i] + " ";
      }
      return ret;
    }
  }

  class Pair implements Comparable<Pair>{
    int x, y;

    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public int compareTo(Pair o) {
      if (this.x != o.x) {
        return this.x - o.x;
      }
      return this.y - o.y;
    }
  }

  void run() {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int k = sc.nextInt();
    int l = sc.nextInt();

    UnionFind kUnionFind = new UnionFind(n);
    UnionFind lUnionFind = new UnionFind(n);

    for (int i = 0; i < k; i++) {
      int p = sc.nextInt() - 1;
      int q = sc.nextInt() - 1;
      kUnionFind.union(p, q);
    }

    for (int i = 0; i < l; i++) {
      int p = sc.nextInt() - 1;
      int q = sc.nextInt() - 1;
      lUnionFind.union(p, q);
    }

    TreeMap<Pair, Integer> map = new TreeMap();
    for (int i = 0; i < n; i++) {
      int parentK = kUnionFind.find(i);
      int parentL = lUnionFind.find(i);
      Pair pair = new Pair(parentK, parentL);
      if (map.containsKey(pair)) {
        map.put(pair, map.get(pair) + 1);
      } else {
        map.put(pair, 1);
      }
    }

    String tab = "";
    for (int i = 0; i < n; i++) {
      int parentK = kUnionFind.find(i);
      int parentL = lUnionFind.find(i);
      Pair pair = new Pair(parentK, parentL);
      int ans = map.get(pair);
      System.out.print(tab + ans);
      tab = " ";
    }
    System.out.println();
  }
 
  public static void main(String[] args) {
    new Main().run();
  }
}
