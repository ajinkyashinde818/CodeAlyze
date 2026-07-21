import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int N = in.nextInt();
    long K = in.nextLong();

    int[] numbers = new int[N];

    for (int i = 0; i < N; i++) {
      numbers[i] = in.nextInt() - 1;
    }

    HashMap<Long, int[]> map = new HashMap<>();

    long index = 1L;
    map.put(index, numbers);
    index *= 2L;

    while (index < K) {
      int[] newNumbers = new int[N];
      long preIndex = index / 2;

      for (int i = 0; i < N; i++) {
        int preLoc = map.get(preIndex)[i];
        int curLoc = map.get(preIndex)[preLoc];
        newNumbers[i] = curLoc;
      }

      map.put(index, newNumbers);
      index *= 2;
    }

    int ans = 0;
    index /= 2;

    while (index > 0) {
      if (K >= index) {
        ans = map.get(index)[ans];
        K -= index;
      }
      index /= 2;
    }

    System.out.println(ans + 1);
  }
}
