import java.util.Scanner;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String ans;

    s = s.replaceAll("eraser", "-");
    s = s.replaceAll("erase", "-");
    s = s.replaceAll("dreamer", "-");
    s = s.replaceAll("dream", "-");
    s = s.replaceAll("-", "");
    
    if (s.length() == 0) {
      ans = "YES";
    } else {
      ans = "NO";
    }
    System.out.println(ans);
    sc.close();
    return;
  }
}
