import java.math.*;
import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    ArrayList<Integer> a = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      a.add(sc.nextInt() - 1);
    }
    ArrayList<Integer> b = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      b.add(sc.nextInt());
    }
    ArrayList<Integer> c = new ArrayList<>();
    for (int i = 0; i < n - 1; i++) {
      c.add(sc.nextInt());
    }
    int result = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      int now = a.get(i);
      result += b.get(now);
      if (prev >= 0 && now == prev + 1) {
        result += c.get(prev);
      }
      prev = now;
    }
    System.out.println(result);
  }
}
