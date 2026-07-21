import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    boolean judgeA = false;
    boolean judgeB = false;
    boolean judgeC = false;
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == 'a') {
        judgeA = true;
      }else if (s.charAt(i) == 'b') {
        judgeB = true;
      }else if (s.charAt(i) == 'c') {
        judgeC = true;
      }
    }
    System.out.println(judgeA && judgeB && judgeC ? "Yes" : "No");
  }

}
