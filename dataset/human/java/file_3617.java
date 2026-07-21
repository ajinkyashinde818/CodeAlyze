import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String X = sc.next();
    String Y = sc.next();

    String msg = "=";
    if(X.charAt(0) < Y.charAt(0)) msg = "<";
    else if(X.charAt(0) > Y.charAt(0)) msg = ">";

    System.out.println(msg);

  }
}
