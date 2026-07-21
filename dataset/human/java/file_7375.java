import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String text = sc.next();
    text = text.replace("eraser", "-");
    text = text.replace("erase", "-");
    text = text.replace("dreamer", "-");
    text = text.replace("dream", "-");
    text = text.replace("-", "");
    if (text.isEmpty()) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
      
  }
}
