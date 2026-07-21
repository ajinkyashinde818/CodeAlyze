import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String ns = sc.next();
    String nt = sc.next();
    char[] sChar = ns.toCharArray();
    char[] tChar = nt.toCharArray();
    Arrays.sort(sChar);
    Arrays.sort(tChar);
    String s = new String(sChar);
    String t_asc = new String(tChar);
    String t = new StringBuilder(t_asc).reverse().toString();
    if (s.compareTo(t) < 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
