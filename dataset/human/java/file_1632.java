import java.util.*;

public class Main {
  private static final int MOD = 1_000_000_007;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String S = sc.next();
    Map<Character, Integer> map = new HashMap<>();
    for (int i = 0; i < N; i++) {
      char c = S.charAt(i);
      map.put(c, map.getOrDefault(c, 0)+1);
    }
    long ans = 1;
    for (int count : map.values()) {
      ans *= count+1;
      ans %= MOD;
    }
    System.out.println(ans-1);
  }
}
