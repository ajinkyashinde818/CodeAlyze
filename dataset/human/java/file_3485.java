import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    String X = "0x" + sc.next();
    String Y = "0x" + sc.next();

    int X16 = Integer.decode(X);
    int Y16 = Integer.decode(Y);

    if (X16 == Y16) {
      System.out.println("=");
    } else if (X16 < Y16) {
      System.out.println("<");
    } else {
      System.out.println(">");
    }

  }
}
