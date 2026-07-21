import java.util.*;

class Main {
  static String[] strs={
    "dream",
    "dreamer",
    "erase",
    "eraser"
  };

  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    String S=sc.next();

    while (true) {
      boolean endsWithStr=false;
      for (String str: strs) {
        if (S.endsWith(str)) {
          endsWithStr=true;
          S=S.substring(0,S.length()-str.length());
          break;
        }
      }
      if (!endsWithStr) {
        System.out.println("NO");
        break;
      }
      if (S.length()<=0) {
        System.out.println("YES");
        break;
      }
    }
  }
}
