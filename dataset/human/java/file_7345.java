import java.util.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);
    
    String S = sc.next();

    sc.close();

    StringBuffer sb =new StringBuffer(S);

    String R = sb.reverse().toString();

    R = R.replaceAll("resare", "");
    R = R.replaceAll("esare", "");
    R = R.replaceAll("remaerd", "");
    R = R.replaceAll("maerd", "");

    if (R.equals("")) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }

  }

}
