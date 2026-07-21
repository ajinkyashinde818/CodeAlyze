import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner scan = new Scanner(System.in);

    int a = scan.nextInt();
    int b = scan.nextInt();
    int k = scan.nextInt();

    for (int i = Math.min(a, b);; i--) {
      if ((a % i == 0) && (b % i == 0)) {
        k--;
        if (k == 0) {
          System.out.println(i);
          return;
        }
      }
    }

  }

}
