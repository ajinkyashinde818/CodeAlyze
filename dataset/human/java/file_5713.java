import java.util.*;
public class Main {
    public static void main (String[] args) {
      Scanner sc = new Scanner(System.in);
      String str = sc.next();
      char[] array = str.toCharArray();
      Arrays.sort(array);
      String sortedStr = new String(array);
      String ans = (sortedStr.equals("abc"))? "Yes" : "No";
      
      System.out.println(ans);
    }
}
