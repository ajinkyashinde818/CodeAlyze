import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] X = sc.next().toCharArray();
    char[] Y = sc.next().toCharArray();
    char ans;
    if (X[0] < Y[0]) {
      ans = '<';
    } else if (X[0] > Y[0]) {
      ans = '>';
    } else {
      ans = '=';
    }
    System.out.println(ans);
  }
}
