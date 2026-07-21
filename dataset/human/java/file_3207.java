import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    if(N % 10 == 9 || N / 10 == 9) {
      System.out.print("Yes");
    } else {
      System.out.print("No");
    }
  }
}
