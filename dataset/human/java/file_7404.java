import java.util.*;

public class Main {
  public static void main(String[] args) {
    @SuppressWarnings("resource")
    Scanner sc = new Scanner(System.in);
    // 前からだと分解できるかわからないので、後ろから分解してみる
    String[] divideArr = {"maerd", "remaerd", "esare", "resare"};
    StringBuilder reverseStr = new StringBuilder(sc.next()).reverse();
    int length = reverseStr.length();

    for (int i = 0; i < length;) {
      boolean isDivided = false;
      for (String s : divideArr) {
        // ぶんかいできたら、分解した次の文字から繰り返す
        if (reverseStr.indexOf(s) == 0) {
          i += s.length();
          reverseStr.delete(0, s.length());
          isDivided = true;
          break;
        }
      }
      if (!isDivided) {
        System.out.println("NO"); // 分解できなかったらおわり
        return;
      }
    }

    System.out.println("YES");
  }
}
