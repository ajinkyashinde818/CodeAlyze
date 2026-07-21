import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    final Scanner scanner = new Scanner(System.in);

    final Integer K = scanner.nextInt();
    final Integer N = scanner.nextInt();

    final List<Integer> As = new ArrayList<>();
    for (Integer i = 0; i < N; i++) {
      As.add(scanner.nextInt());
    }

    int max = K - (As.get(As.size() - 1) - As.get(0));
    for (int i = 0; i < As.size() - 1; i++) {
      final int diff = As.get(i + 1) - As.get(i);
      max = Math.max(diff, max);
    }
      System.out.println(K - max);
  }
}
