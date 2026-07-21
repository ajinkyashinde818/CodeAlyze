import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int R = scanner.nextInt();
    System.out.println(N >= 10 ? R : R + (10 - N) * 100);
  }
}
