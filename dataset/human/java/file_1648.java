import java.util.*;

class Main {
  private static final long MOD_CONST = 1000000007;
  
  private static long mul(long a, long b) {
    return a * b % 1000000007;
  }
  
  private static long solve(String text) {
    int[] count = new int[26];
    for (char c: text.toCharArray()) {
      count[c - 'a']++;
    }
    long result = 1;
    for (long c : count) {
      result = mul(result, (c + 1));
    }
    
    result--;
    result += MOD_CONST;
    result %= MOD_CONST;
    return result;
  }
  
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    
    int n = s.nextInt();
    String text = s.next();
    
    System.out.println(solve(text));
  }
}
