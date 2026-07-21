import java.util.*;

public class Main {
  public static void main(String... args) {
    Scanner input = new Scanner(System.in);
    
    int n = input.nextInt();
    long k = input.nextLong();
    
    int[] A = new int[n];
    for (int i = 0; i < n; i++) {
      A[i] = input.nextInt();
    }
    
    long step = 0;
    int cur = 1;
    Set<Integer> vis = new HashSet<>();
    while (true) {
      if (vis.contains(cur)) {
        break;
      }
      vis.add(cur);
      step++;
      cur = A[cur - 1];
      if (step == k) {
        System.out.println(cur);
        return;
      }
    }
    
    if (cur != 1) {
      int start = A[0];
      int initialLen = 1;
      while (start != cur) {
        initialLen++;
        start = A[start - 1];
      }

      k -= initialLen;
    }
    
    List<Integer> list = new ArrayList<>();
    list.add(cur);
    int start = A[cur - 1];
    while (start != cur) {
      list.add(start);
      start = A[start - 1];
    }
    
    k %= list.size();
    
    System.out.println(list.get((int)k));
  }
}
