import java.util.Scanner;
import java.util.SplittableRandom;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static long[] buf = new long[200000];

  public static void main(String[] args) {
    SplittableRandom rnd = new SplittableRandom();

//    for (int turn = 0; turn < 1000000; turn++) {
//      int N = rnd.nextInt(10) + 1;
//      long[] A = new long[N];
//      long[] B = new long[N];
//      for (int i = 0; i < N; i++) {
//        A[i] = rnd.nextInt(1 << 28);
//        B[i] = rnd.nextInt(1 << 28);
//      }
//      long brute = 0;
//      for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//          brute ^= A[i] + B[j];
//        }
//      }
//      System.err.println("brute:" + brute);

    int N = sc.nextInt();
    long[] A = new long[N];
    long[] B = new long[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    for (int i = 0; i < N; i++) {
      B[i] = sc.nextInt();
    }

      int ans = 0;
      for (int i = 0; i < 30; i++) {
        int bb = 0;
        for (int j = 0; j < N; j++) {
          if ((B[j] & (1 << i)) != 0) ++bb;
        }
        int bbAll = bb;
        long mask = (1L << i) - 1;
        long count = 0;
        int bp = N;
        for (int j = 0; j < N; j++) {
          long av = A[j] & mask;
          while (bp > 0) {
            if ((av + (B[bp - 1] & mask)) <= mask) {
              break;
            }
            --bp;
            if ((B[bp] & (1 << i)) != 0) --bb;
          }
          if ((A[j] & (1 << i)) == 0) {
            // zero & carry or one & no carry
            count += bb;
            count += N - bp - (bbAll - bb);
          } else {
            // zero & no carry or one & carry
            count += bp - bb;
            count += bbAll - bb;
          }
        }
        if (count % 2 == 1) ans |= 1 << i;
        sort(A, i);
        sort(B, i);
      }
//      if (brute != ans) {
//        System.out.println(turn);
//        System.out.println(Arrays.toString(A));
//        System.out.println(Arrays.toString(B));
//        System.out.println(brute);
//        System.out.println(ans);
//        System.exit(0);
//      }
      System.out.println(ans);
//    }
  }

  static void sort(long[] a, int k) {
    int ap = 0;
    int bp = 0;
    long bit = 1L << k;
    for (int i = 0; i < a.length; i++) {
      if ((a[i] & bit) == 0) {
        a[ap++] = a[i];
      } else {
        buf[bp++] = a[i];
      }
    }
    for (int i = 0; i < bp; i++) {
      a[ap++] = buf[i];
    }
  }

}
