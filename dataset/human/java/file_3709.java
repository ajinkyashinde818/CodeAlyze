import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);

      String a = in.next();
      String b = in.next();

      int ans = a.compareTo(b);

      if(ans < 0) {
          System.out.println("<");
      }
      else if(ans == 0) {
          System.out.println("=");
      }
      else {
          System.out.println(">");
      }



    }
}
