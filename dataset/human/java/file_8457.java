import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
public class Main {
  public static void main(String[] args) {
    Main m = new Main();
    m.run();
  }
  private void run() {
    int n = 0;
    int k = 0;
    int l = 0;
    UnionFind ufk = null;
    UnionFind ufl = null;
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));) {
      String[] t = br.readLine().split("\\s+");
      n = Integer.parseInt(t[0]);
      k = Integer.parseInt(t[1]);
      l = Integer.parseInt(t[2]);
      ufk = new UnionFind(n);
      ufl = new UnionFind(n);
      for (int i=0;i<k;i++) {
        t = br.readLine().split("\\s+");
        int p = Integer.parseInt(t[0])-1;
        int q = Integer.parseInt(t[1])-1;
        ufk.unite(p,q);
      }
      for (int i=0;i<l;i++) {
        t = br.readLine().split("\\s+");
        int r = Integer.parseInt(t[0])-1;
        int s = Integer.parseInt(t[1])-1;
        ufl.unite(r,s);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
    Map<Tuple,Integer> m = new HashMap<>();
    for (int i=0;i<n;i++) {
      Tuple t = new Tuple(ufk.find(i),ufl.find(i));
      if (m.containsKey(t)) {
        int v = m.get(t);
        m.put(t,v+1);
      } else {
        m.put(t,1);
      }
    }
    for (int i=0;i<n;i++) {
      if (i > 0) System.out.print(" ");
      Tuple t = new Tuple(ufk.find(i),ufl.find(i));
      System.out.print(m.get(t));
    }
    System.out.println();
  }
  private class Tuple {
    int x;
    int y;
    Tuple(int x,int y) {
      this.x = x;
      this.y = y;
    }
    @Override
    public int hashCode() {
      int prime = 31;
      int result = 1;
      result = prime * result + x;
      result = prime * result + y;
      return result;
    }
    @Override
    public boolean equals(Object obj) {
      if (this == obj) return true;
      if (obj == null) return false;
      if (getClass() != obj.getClass()) return false;
      Tuple other = (Tuple)obj;
      return x == other.x && y == other.y;
    }
  }
  private class UnionFind {
    int n;
    int[] par;
    int[] rank;
    UnionFind(int n) {
      this.n = n;
      par = new int[n];
      rank = new int[n];
      for (int i=0;i<n;i++) par[i] = i;
    }
    private int find(int i) {
      if (par[i] == i) return i;
      return par[i] = find(par[i]);
    }
    private boolean same(int i,int j) {
      return find(i) == find(j);
    }
    private void unite(int i,int j) {
      i = find(i);
      j = find(j);
      if (i == j) return;
      if (rank[i] < rank[j]) {
        par[i] = j;
      } else {
        par[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
      }
    }
  }
}
