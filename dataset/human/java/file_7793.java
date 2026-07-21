import java.math.BigInteger;
import java.util.*;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    BigInteger k = new BigInteger(sc.next());
    List<Integer> a = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      a.add(sc.nextInt() - 1);
    }

    int mInt = 200001;
    BigInteger m = new BigInteger(Integer.toString(mInt));
    int p = 0;
    if (k.compareTo(m) <= 0) {
      int kInt = k.intValue();
      for (int i = 0; i < kInt; i++) {
        p = a.get(p);
      }
      System.out.println(p + 1);
      return;
    }
    Map<Integer, Integer> cMap = new HashMap<>();
    int startLoop = 0;
    int startTown = 0;
    int loopCount = 0;
    for (int i = 1; i <= mInt; i++) {
      p = a.get(p);
      Integer c = cMap.get(p);
      if (c != null) {
        startLoop = c;
        startTown = p;
        loopCount = i - c;
        break;
      }
      cMap.put(p, i);
    }
    int r = k.subtract(new BigInteger(Integer.toString(startLoop - 1))).mod(new BigInteger(Integer.toString(loopCount))).intValue();
    p = startTown;
    for (int i = 0, len = (r == 0 ? loopCount : r) - 1; i < len; i++) {
      p = a.get(p);
    }
    System.out.println(p + 1);
  }
}
