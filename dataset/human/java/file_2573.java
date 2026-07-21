import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
  private static Character[] toCharacter(String str) {
    Character ary[] = new Character[str.length()];
    for (int i = 0; i < str.length(); ++i) {
      ary[i] = str.charAt(i);
    }
    return ary;
  }
  
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String _s = sc.next();
    String _t = sc.next();

    Character[] s = toCharacter(_s);
    Arrays.sort(s);

    Character[] t = toCharacter(_t);
    Arrays.sort(t, new Comparator<Character>() {
      @Override
      public int compare(Character a, Character b) {
        if (a < b) return 1;
        else if (a > b) return -1;
        else return 0;
      }
    });

    int i = 0;
    while (i < s.length && i < t.length && s[i] == t[i]) ++i;

    if ((i != s.length && i != t.length && s[i] < t[i]) || (i == s.length && i != t.length))  {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }   

    sc.close(); 
  }
}
