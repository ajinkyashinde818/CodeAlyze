import java.util.*;
import java.io.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);

    String s = sc.next();
    String t = sc.next();

    sc.close();

    String[] S = s.split("");
    String[] T = t.split("");

    Arrays.sort(S);
    Arrays.sort(T, Comparator.reverseOrder());

    String s_ = "";
    String t_ = "";

    for (int i = 0; i < S.length; i++) {
      s_ += S[i];
    }

    for (int i = 0; i < T.length; i++) {
      t_ += T[i];
    }

    int c = s_.compareTo(t_);

    if (c < 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }

  }

}
