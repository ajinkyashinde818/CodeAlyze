import java.util.*;

class Main {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int K = sc.nextInt();
    int S = sc.nextInt();
    int count = 0;
    for (int a = 0; a <= K; a++) {
      for (int b = 0; b <= K; b++) {
        if (S - (a + b) <= K && S - (a + b) >= 0) count++;
      }
    }
    System.out.println(count);
  }
}
