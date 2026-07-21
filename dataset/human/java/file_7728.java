import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    long k = sc.nextLong();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt() - 1;
    }

    int step = 0;
    int pos = 0;
    int[] flg = new int[n];
    flg[pos] = -1;
    int len = 0; //サイクルの長さ

    while (true) {
      pos = a[pos];
      if (++step == k) {
        System.out.println(pos + 1);
        return;
      }

      if (flg[pos] != 0) {
        if (pos == 0) {
          len = step;
        } else {
          len = step - flg[pos];
        }
        break;
      }

      flg[pos] = step;
    }

    if (pos != 0) {
      k -= flg[pos];
    }

    k %= len;

    for (int i = 0; i < k; i++) {
      pos = a[pos];
    }

    System.out.println(pos + 1);
  }
}
