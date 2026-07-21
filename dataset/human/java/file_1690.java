import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.next());
    String S = sc.next();
    int[] val = new int[26];
    for(int i = 0; i < N; i++){
      int n = S.charAt(i)-'a';
      val[n]++;
    }
    
    int mod = 1000000007;
    long ans = 1;
    for(int i = 0; i < 26; i++){
      ans *= val[i]+1;
      ans %= mod;
    }
    
    System.out.println(ans-1);
  }
}
