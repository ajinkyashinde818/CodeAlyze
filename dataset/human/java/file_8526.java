import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int lhs = scanner.nextInt();
    int rhs = scanner.nextInt();
    int k = scanner.nextInt();

    int sqrt = (int)Math.sqrt(rhs);
    TreeSet<Integer> set = new TreeSet<Integer>();
    for (int ix = 1; ix <= Math.min(lhs, rhs); ix++) {
      if (lhs % ix == 0 && rhs % ix == 0) {
        set.add(ix);
      }
    }

    Iterator<Integer> it = set.descendingIterator();
    while (--k > 0) {
      it.next();
    }

    System.out.println(it.next());
  }
}
