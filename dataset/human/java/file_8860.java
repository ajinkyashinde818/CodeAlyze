import java.util.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();

    sc.close();

    int C = A;

    if (A < B) {
      C = B;
    }

    Deque<Integer> deque = new ArrayDeque<>();

    for (int i = 1; i <= C; i++) {
      if ((A % i == 0) && (B % i == 0)) {
        deque.push(i);
      }
    }

    int s = 0;

    for (int i = 0; i < K; i++) {
      s = deque.pollFirst();
    }

    System.out.println(s);

  }

}
