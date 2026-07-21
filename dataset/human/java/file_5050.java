import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String S = scanner.next();
    int Q = scanner.nextInt();
    StringBuilder head = new StringBuilder();
    StringBuilder tail = new StringBuilder();
    boolean reverse = false;
    for (int i = 0; i < Q; i++) {
      int T = scanner.nextInt();
      switch (T) {
        case 1:
          reverse = !reverse;
          break;
        case 2:
          int F = scanner.nextInt();
          char C = scanner.next().charAt(0);
          if (F == 1 && !reverse || F == 2 && reverse) head.append(C);
          else tail.append(C);
          break;
      }
    }
    head.reverse().append(S).append(tail.toString());
    if (reverse) System.out.println(head.reverse().toString());
    else System.out.println(head.toString());
  }
}
