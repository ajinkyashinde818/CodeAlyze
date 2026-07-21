import java.util.*;
public class Main{

  public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();

      Map<Integer, Set<Integer>> graph = new HashMap<>();
      for(int i = 1; i <= n; i++) {
          graph.put(i, new HashSet<>());
      }

      for(int i = 0; i < m; i++) {
          int u = sc.nextInt();
          int v = sc.nextInt();
          graph.get(u).add(v);
          graph.get(v).add(u);
      }

      for(int island : graph.get(1)) {
          if(graph.get(island).contains(n)) {
            System.out.println("POSSIBLE");
            return;
          }
      }
      System.out.println("IMPOSSIBLE");
  }
}
