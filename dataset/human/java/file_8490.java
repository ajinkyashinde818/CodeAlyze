import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int l = sc.nextInt();
		UnionFindTree kTree = new UnionFindTree(n);
		for (int i = 0; i < k; i++) {
		    kTree.unite(sc.nextInt() - 1, sc.nextInt() - 1);
		}
		UnionFindTree lTree = new UnionFindTree(n);
		for (int i = 0; i < l; i++) {
		    lTree.unite(sc.nextInt() - 1, sc.nextInt() - 1);
		}
		HashMap<Long, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
		    long key = kTree.find(i) * (long)n + lTree.find(i);
		    if (map.containsKey(key)) {
		        map.put(key, map.get(key) + 1);
		    } else {
		        map.put(key, 1);
		    }
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
		    if (i != 0) {
		        sb.append(" ");
		    }
		    long key = kTree.find(i) * (long)n + lTree.find(i);
		    sb.append(map.get(key));
		}
		System.out.print(sb);
   }
   
   static class UnionFindTree {
       int[] parents;
       
       public UnionFindTree(int size) {
           parents = new int[size];
           for (int i = 0; i < size; i++) {
               parents[i] = i;
           }
       }
       
       public int find(int x) {
           if (parents[x] == x) {
               return x;
           } else {
               return parents[x] = find(parents[x]);
           }
       }
       
       public void unite(int x, int y) {
           int xx = find(x);
           int yy = find(y);
           if (xx == yy) {
               return;
           }
           parents[xx] = yy;
       }
   }
}
