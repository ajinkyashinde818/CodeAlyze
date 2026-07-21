import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int skill[][] = new int [n][m];
    int price[] = new int[n];
    int res = Integer.MAX_VALUE;
    for (int i = 0; i < n; i++) {
      price[i] = sc.nextInt();
      for (int j = 0; j < m; j++) {
        skill[i][j] = sc.nextInt();
      }
    }
    for (int i = 0; i < (int)Math.pow(2, n); i++) {
      String tmp = Integer.toBinaryString(i);
      int sumPri = 0;
      int und[] = new int[m];
      Arrays.fill(und, 0);
      for (int j = 0; j < tmp.length(); j++) {
        if (tmp.charAt(tmp.length()-1-j) == '0') continue;
        for (int k = 0; k < m; k++) {
          und[k] += skill[j][k];
        }
        sumPri += price[j];
      }
      int min = Integer.MAX_VALUE;
      for (int j = 0; j < m; j++) {
        min = Math.min(min, und[j]);
      }
      if (min >= x) {
        res = Math.min(res, sumPri);
      }
    }
    if (res == Integer.MAX_VALUE) res = -1;
    System.out.println(res);
    // for (int i = 0; i < n; i++) {
    //   int ind = price[i].index;
    //   int tmp = Integer.MAX_VALUE;
    //   for (int j = 0; j < m; j++) {
    //     und[j] += skill[ind][j];
    //     tmp = Math.min(tmp, und[j]);
    //   }
    //   res += price[i].price;
    //   if (tmp >= x) {
    //     System.out.println(res);
    //     return;
    //   }
    // }
    // System.out.println(-1);
    sc.close();
  }

  static class Data implements Comparable<Data>{
    int index; int price;
    Data(int index, int price) {
      this.index = index;
      this.price = price;
    }

    @Override
    public int compareTo(Data o) {
      return Integer.compare(price, o.price);
    }
  }
}
