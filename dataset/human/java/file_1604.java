import java.util.*;
public class Main {

  public static void main(String[] args) { 
      final int MOD = 1_000_000_007;
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      String s = sc.next();
      int[] freq = new int[26];
      for(char c : s.toCharArray())
        freq[c-'a']++;

      long cnt = 1;
      for(int i = 0; i < freq.length; i++) {
        cnt = cnt * (freq[i] + 1) % MOD;
      }
      System.out.println(cnt - 1);
  }
}
