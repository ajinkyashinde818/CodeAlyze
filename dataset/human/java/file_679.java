import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int R = sc.nextInt();
    int n = R;
    
    if (N < 10) {
      n = R + (100 * (10 - N));
    }
    
    System.out.println(n);
  }
}
