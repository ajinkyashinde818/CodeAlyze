import java.util.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);
    
    int N = sc.nextInt();
    int M = sc.nextInt();
    
    // a_iが1のとき、start[b_i]はtrue
    boolean[] start = new boolean[N+1];

    // b_iがNのとき、goal[a_1]はtrue
    boolean[] goal = new boolean[N+1];

    for (int i = 0; i < M; i++) {
      int a_ = sc.nextInt();
      int b_ = sc.nextInt();
      if (a_ == 1) {
        start[b_] = true;
      }
      if (b_ == N) {
        goal[a_] = true;
      }
    }

    sc.close();
    
    String result = "IMPOSSIBLE";

    for (int i = 0; i < N; i++) {
      if (start[i] && goal[i]) {
        result = "POSSIBLE";
        break;
      }
    }

    System.out.println(result);

  }

}
