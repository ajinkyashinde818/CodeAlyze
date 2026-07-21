import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] d1 = new int[n];
    int[] d2 = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
      d1[i] = sc.nextInt();
      d2[i] = sc.nextInt();
    }
    for (int i = 0; i < n - 2; i++) {
      if (d1[i] == d2[i] && d1[i + 1] == d2[i + 1] && d1[i + 2] == d2[i + 2]) {
        count++;
      }
    }
    if (count > 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
