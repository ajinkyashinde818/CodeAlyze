import java.util.Arrays;
import java.util.Scanner;

public class Main {

  Scanner sc;

  Main() {
    sc = new Scanner(System.in);
  }

  public static void main(String[] args) {
    new Main().run();
  }

  void run() {
    int sum = 0;

    for(int i = 0; i < 10; ++i) {
      sum += ni();
    }

    System.out.println(sum);

  }

  int ni() {
    return Integer.parseInt(sc.next());
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }
}
