import java.util.Scanner;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    try {
      int a = scanner.nextInt();
      int b = scanner.nextInt();
      int c = scanner.nextInt();

      int doku = Math.min(a+b+1,c);
      int ans = b + doku;
      System.out.print(ans);
    } finally {
      scanner.close();
    }
  }
}
