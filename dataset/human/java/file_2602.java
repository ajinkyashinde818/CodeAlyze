import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();
    char[] t = sc.next().toCharArray();
    
    Arrays.sort(s);
    Arrays.sort(t);
    char[] tt = new char[t.length];
    for (int i = 0; i < tt.length; i++) {
      tt[i] = t[t.length-1-i];
    }
    
    String S = String.valueOf(s);
    String T = String.valueOf(tt);
    
    System.out.println(S.compareTo(T) < 0 ? "Yes" : " No");
  }
}
