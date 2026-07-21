import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();

    System.out.println(calcLCM(a, b));
  }

  private static long calcLCM(int a, int b) {
    long maxValue = Math.max(a, b);
    long minValue = Math.min(a, b);

    long val = maxValue * minValue;
    if (minValue == 0) {
      return (int) maxValue;
    }

    long c;
    while( (c = maxValue % minValue) != 0 ) {
      maxValue = minValue;
      minValue = c;
    }

    return (val / minValue);
  }
}
