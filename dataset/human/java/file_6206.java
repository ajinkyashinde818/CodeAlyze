import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int S = sc.nextInt();
    int count = 0;
    for (int x = 0; x <= K; x++) {
      for (int y = 0; y <= K; y++) {
        if (0 <= S-(x+y) && S-(x+y) <= K) {
          count++;
        }
      }
    }
    System.out.println(count);
  }
}
