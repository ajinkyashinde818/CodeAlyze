import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int A = in.nextInt();
    int B = in.nextInt();
    int K = in.nextInt();

    List<Integer> list = new ArrayList<Integer>();

    for (int i = 1; i <= Math.min(A, B); i++) {
      if (A % i == 0 && B % i == 0) {
        list.add(i);
      }
    }

    System.out.println(list.get(list.size() - K));
  }
}
