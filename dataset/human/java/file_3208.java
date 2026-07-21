import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String N = sc.next();

    String msg = "No";
    if(N.charAt(0) == '9' || N.charAt(1) == '9')msg = "Yes";


    System.out.println(msg);

  }
}
