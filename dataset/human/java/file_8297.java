import java.util.*;

class Main {
    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      long A = sc.nextLong();
      long B = sc.nextLong();
      long lcm, x, y, tmp;

      if(A < B) {
        x = B;
        y = A;
      } else {
        x = A;
        y = B;
      }
      while ((tmp = x % y) != 0) {
          x = y;
          y = tmp;
      }
      lcm = (A * B) / y;
      System.out.println(lcm);
    }
}
