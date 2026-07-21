import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);

      String str = in.next();
      int len = str.length();
      String ans = str.substring(0,len-8);

      System.out.println(ans);

    }
}
