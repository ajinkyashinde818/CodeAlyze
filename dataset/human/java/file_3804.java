import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      String s = sc.next();
      StringBuilder sb = new StringBuilder();
      for(char c : s.toCharArray()) {
        if(c == 'x') continue;
        sb.append(c);
      }
      if(!isPalin(sb.toString())) {
        System.out.println(-1);
        return;
      }
      int cnt = 0;
      int left = 0, right = s.length() - 1;
      while(left < right) {
        if(s.charAt(left) == s.charAt(right)) {
          left++;
          right--;
        } else if(s.charAt(left) == 'x') {
          cnt++;
          left++;
        } else if(s.charAt(right) == 'x') {
          cnt++;
          right--;
        }

      }
      System.out.println(cnt);
  }
  
  private static boolean isPalin(String s) {
    int left = 0, right = s.length()-1;
    while(left < right) {
      if(s.charAt(left) != s.charAt(right)) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
}
