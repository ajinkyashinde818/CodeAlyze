import java.util.*;

public class Main {  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] a = new int[M];
    int[] b = new int[M];
    Set<Integer> setA = new HashSet<Integer>();
    Set<Integer> setB = new HashSet<Integer>();
    for (int i =0; i<M; i++) {
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
      if (a[i] == 1) {
        setA.add(b[i]);
      }
      if (b[i] == N) {
        setB.add(a[i]);
      }
    }
    boolean OK = false;
    for (int x : setA) {
      if (setB.contains(x) ) {
        OK = true;
        break;
      }
    }
    if (OK) {
      System.out.print("POSSIBLE");
    } else {
      System.out.print("IMPOSSIBLE");
    }
  }
}
