import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    String[] ss = s.split("");
    Arrays.sort(ss);
    String strs = String.join("", ss);
    String t = sc.nextLine();
    String[] tt = t.split("");
    Arrays.sort(tt, Comparator.reverseOrder());
    String strt = String.join("", tt);
    if (strs.compareTo(strt) < 0)
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}
