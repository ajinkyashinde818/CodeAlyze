import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      long A = in.nextInt();
      long B = in.nextInt();
      long C = in.nextInt();
      
      if (A + B >= C) {
        System.out.println(B + C);
      } else {
        System.out.println(2 * (A + B) + 1 - A);
      }
    }
  }
}
