import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] N = sc.next().toCharArray();
    
    for (char c : N) {
      if (c == '9') {
        System.out.println("Yes");
        return;
      }
    }
    System.out.println("No");
  }
}
