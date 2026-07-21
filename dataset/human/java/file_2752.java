import java.util.*;
import java.math.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();

    String[] data1 = new String[s.length()];
    String[] data2 = new String[t.length()];

    for (int i = 0; i < s.length(); i++) {
      data1[i] = s.substring(i,i+1);
    }

    for (int i = 0; i < t.length(); i++) {
      data2[i] = t.substring(i,i+1);
    }

    Arrays.sort(data1);
    Arrays.sort(data2);

    String n = data1[0];
    String m = data2[data2.length-1];

    for (int i = 1; i < data1.length; i++) {
      n += data1[i];
    }

    for (int i = data2.length-2; i >= 0; i--) {
      m += data2[i];
    }

    if (n.compareTo(m) < 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }

}
