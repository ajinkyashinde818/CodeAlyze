import java.util.*;
import java.math.*;
import java.lang.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();

    int[] a = new int[m];
    int[] b = new int[m];


    for (int i = 0; i < m; i++) {
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
    }

    Set<Integer> s1 = new HashSet<Integer>();
    Set<Integer> s2 = new HashSet<Integer>();

    for (int i = 0; i < m; i++) {
      if (a[i] == 1) {
        s1.add(b[i]);
      }

      if (b[i] == n) {
        s2.add(a[i]);
      }
    }

    // for (Integer value : list2) {
    //   System.out.println(value);
    // }

  for (Integer i : s2) {
    if (s1.contains(i)) {
      System.out.println("POSSIBLE");
      return;
    }
  }

  System.out.println("IMPOSSIBLE");




  }

}
