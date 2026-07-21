import java.util.Scanner;
import java.util.ArrayList;

public class Main {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      int A = in.nextInt();
      int B = in.nextInt();
      int K = in.nextInt();

      ArrayList<Integer> commonDivisor = new ArrayList<Integer>();

      for (int i = 1; i <= 100; ++i) {
        if (A % i == 0 && B % i == 0) {
          commonDivisor.add(i);
        } 
      }

      System.out.println(commonDivisor.get(commonDivisor.size() - K));
    }
  }
}
