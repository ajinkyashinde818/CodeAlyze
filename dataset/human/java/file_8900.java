import java.util.*;

public class Main {
  static int[] list;
    public static void main(String[] args) throws Exception{
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt();
      int cnt = 0;
      for (int i = 100; 1 <= i; i--) {
        if (a%i==0 && b%i==0) {
          cnt++;
          if (cnt == k) {
            System.out.println(i);
            break;
          }
        }
      }
    }
}
