import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    char[] S = scanner.next().toCharArray();
    long M = 1_000_000_007;
    HashMap<Character, Integer> freq = new HashMap<>();
    long res = 0;
    for (char ch : S) {
      long c = 1;
      for (Map.Entry<Character, Integer> e : freq.entrySet()) {
        if (e.getKey() != ch) {
          c *= e.getValue() + 1;
          c %= M;
        }
      }
      res += c;
      if (res >= M) res -= M;
      freq.put(ch, freq.getOrDefault(ch, 0) + 1);
    }
    System.out.println(res);
  }
}
