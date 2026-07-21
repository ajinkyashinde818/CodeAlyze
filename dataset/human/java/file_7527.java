import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String ans = "YES";
    int p = s.length() - 1;
    while(p >= 0) {
      if(s.charAt(p) == 'm') {
        if((s.charAt(p - 1) == 'a') && (s.charAt(p - 2) == 'e') && (s.charAt(p - 3) == 'r') && (s.charAt(p - 4) == 'd')) {
          p -= 5;
        } else {
          ans = "NO";
          break;
        }
      } else if(s.charAt(p) == 'e') {
        if((s.charAt(p - 1) == 's') && (s.charAt(p - 2) == 'a') && (s.charAt(p - 3) == 'r') && (s.charAt(p - 4) == 'e')) {
          p -= 5;
        } else {
          ans = "NO";
          break;
        }
      } else {
        if((s.charAt(p) == 'r') && (s.charAt(p - 1) == 'e') && (s.charAt(p - 2) == 'm') && (s.charAt(p - 3) == 'a') && (s.charAt(p - 4) == 'e') && (s.charAt(p - 5) == 'r') && (s.charAt(p - 6) == 'd')) {
          p -= 7;
        } else if((s.charAt(p) == 'r') && (s.charAt(p - 1) == 'e') && (s.charAt(p - 2) == 's') && (s.charAt(p - 3) == 'a') && (s.charAt(p - 4) == 'r') && (s.charAt(p - 5) == 'e')) {
          p -= 6;
        } else {
          ans = "NO";
          break;
        }
      }
    }
    System.out.println(ans);
  }
}
