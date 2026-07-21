import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long A = sc.nextLong();
    long B = sc.nextLong();
    sc.close();
    long bigger = Math.max(A, B);
    long i = bigger;
    while (true) {
      if (i % A == 0 && i % B == 0) {
        System.out.println(i);
        break;
      }
      i += bigger;
    }
  }
}
