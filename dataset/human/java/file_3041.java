import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    
    List<List<Integer>> nodes = new ArrayList<>();
    for (int i = 0; i <= N; i++) {
      nodes.add(new ArrayList<>());
    }
    for (int i = 0; i < M; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      nodes.get(a).add(b);
    }
    
    // dfs
    boolean success = dfs(1, N, 0, nodes);
    
    System.out.println(success ? "POSSIBLE" : "IMPOSSIBLE");
  }
  
  private static boolean dfs(int from, int to, int depth, List<List<Integer>> nodes) {
    
    if (depth > 2) {
      return false;
    }
    if (from == to) {
      return true;
    }
    
    List<Integer> nextNodes = nodes.get(from);
    for (int nextNode : nextNodes) {
      if (dfs(nextNode, to, depth+1, nodes)) {
        return true;
      }
    }
    
    return false;
  }
}
