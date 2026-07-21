import java.util.*;

public class Main {
  public static void main(String[] args) {
    @SuppressWarnings("resource")
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();
    char[] t = sc.next().toCharArray();

    // 辞書順で s′ < t′となるようにできるか。
    // 辞書順が最も小さいs'と辞書順が最も大きいt'を比べる
    Arrays.sort(s);
    String s2 = String.valueOf(s);
    Arrays.sort(t);
    String t2 = new StringBuilder(String.valueOf(t)).reverse().toString();

    System.out.println(s2.compareTo(t2) < 0 ? "Yes" : "No");
  }
}
