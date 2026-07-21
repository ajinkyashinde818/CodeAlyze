import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();
    char[] t = sc.next().toCharArray();
    ArrayList<Character> s_array = new ArrayList<>();
    ArrayList<Character> t_array = new ArrayList<>();
    for (int i = 0; i < s.length; i++) {
      s_array.add(s[i]);
    }
    for (int i = 0; i < t.length; i++) {
      t_array.add(t[i]);
    }
    Collections.sort(s_array);
    Collections.sort(t_array, Comparator.reverseOrder());
    for (int i = 0; i < s_array.size(); i++) {
      s[i] = s_array.get(i);
    }
    for (int i = 0; i < t_array.size(); i++) {
      t[i] = t_array.get(i);
    }
    String ss = new String(s);
    String tt = new String(t);
    if (ss.compareTo(tt) < 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
