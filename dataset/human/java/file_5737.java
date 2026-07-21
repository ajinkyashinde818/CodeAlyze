import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String ans = "No";
    int p = 0;
    int q = 0;
    int r = 0;
    for(int i = 0; i < 3; i++) {
      if(s.charAt(i) == 'a') p++;
      if(s.charAt(i) == 'b') q++;
      if(s.charAt(i) == 'c') r++;
    }
    if((p > 0) && (q > 0) && (r > 0)) ans = "Yes";
    System.out.println(ans);
  }
}
