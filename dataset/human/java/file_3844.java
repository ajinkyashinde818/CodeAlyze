import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    
    long ans = 0;

    ArrayList<Integer> list = new ArrayList<Integer>();
    ArrayList<String> str = new ArrayList<String>();

    int t = 0;
    int f = 0;

    for(int i = 0; i < s.length(); i++) {
      String a = String.valueOf(s.charAt(i));
      if(!(a.equals("x"))) {
        f++;
        str.add(a);
        list.add(t);
        t = 0;
      } else {
        t++;
      }
    }

    list.add(t);

    int flg = 0;
    if(f == 0) {
      
    } else {
      for(int i = 0; i < str.size(); i++) {
        if(!((str.get(i)).equals(str.get(str.size() - 1 - i)))) flg++;
      }
      if(flg == 0) {
        for(int i = 0; i < list.size(); i++) {
          ans += (long)Math.abs(list.get(i) - list.get(list.size() - 1 - i));
        }
        ans /= 2;
      } else {
        ans = -1;
      }
    }
    
    System.out.println(ans);
  }
}
