import java.util.Arrays;
import java.util.Scanner;

public class Main {

  Scanner sc;

  Main() {
    sc = new Scanner(System.in);
  }

  int ni() {
    return sc.nextInt();
  }

  public static void main(String[] args) {
    new Main().run();
  }

  static int[] LUT;
  static {
    LUT = new int[10001];
    LUT['m'] = 1000;
    LUT['c'] = 100;
    LUT['x'] = 10;
    LUT['i'] = 1;
    LUT[1000] = 'm';
    LUT[100] = 'c';
    LUT[10] = 'x';
    LUT[1] = 'i';
  }

  int encode(String str) {
    int sum = 0;
    int stack = 1;
    for(char c : str.toCharArray()) {
      switch(c) {
        case 'm':
        case 'c':
        case 'x':
        case 'i':
          sum += stack * LUT[c];
          stack = 1;
          break;
        default:
          stack = c - '0';
      }
    }
    return sum;
  }

  String decode(int num) {
    String str = "";
    for(int i = 1000; 0 < i; i /= 10) {
      int k = num/i;
      if (k > 1) {
        str += k;
      }
      if (k != 0) {
        str += (char)LUT[i];
      }
      num %= i;
    }
    return str;
  }

  void run() {
    int n = ni();
    for (int i = 0; i < n; ++i) {
      String left = sc.next();
      String right = sc.next();
      System.out.println(decode(encode(left) + encode(right)));
    }
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }
}
