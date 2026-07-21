import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String ans = "No";
    int n = sc.nextInt();
    int zoro = 0;
    for (int cnt = 0; cnt < n; cnt++) {
      int d1 = sc.nextInt();
      int d2 = sc.nextInt();
      if (d1 == d2) {
        zoro++;
        if (zoro == 3) {
          ans = "Yes";
        }
      } else {
        zoro = 0;
      }
    }
    System.out.println(ans);
    sc.close();
  }
}
