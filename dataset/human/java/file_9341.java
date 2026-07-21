import java.math.*;
import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int count = 0;
    for (int i = 0; i < n; i++) {
      boolean b = sc.nextInt() == sc.nextInt();
      if (b) {
        count++;
        if (count >= 3) {
          System.out.println("Yes");
          return;
        }
      } else {
        count = 0;
      }
    }
    System.out.println("No");
  }
}
