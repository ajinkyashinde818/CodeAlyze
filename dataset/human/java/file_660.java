import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    final int n = scanner.nextInt();
    final int r = scanner.nextInt();

    if(n >= 10) {
      System.out.println(r);
    } else {
      System.out.println(r + 100 * (10-n));
    }

  }

}
