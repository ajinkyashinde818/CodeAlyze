import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();

    ArrayList divs = new ArrayList();

    for (int i=1; i<=A*B; i++) {
      if (A % i == 0 && B % i == 0) {
        divs.add(i);
      }
    }

    System.out.println(divs.get(divs.size() - K));

  }
}
