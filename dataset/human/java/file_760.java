import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
    int R = scan.nextInt();
    if (N < 10) {
      R += 100 * (10 - N);
    }
    System.out.printf("%d\n", R);
  }
}
