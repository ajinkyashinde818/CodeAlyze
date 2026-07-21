import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    String N = sc.next();
    String Ns = N.substring(0,1);
    String Ne = N.substring(N.length() - 1);

    if (Ns.equals("9") || Ne.equals("9")) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

  }
}
