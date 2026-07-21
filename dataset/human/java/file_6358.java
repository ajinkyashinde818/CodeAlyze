import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    //整数の入力
    int K = sc.nextInt();
    int S = sc.nextInt();
    
    int count = 0;
    // 計算
    for (int x=0; x<=K; x++) {
      for (int y=0; y<=K; y++) {
        int z = S - x - y;
        if (z>=0 && z<=K) {
          count += 1;
        }
      }
    }
    // 出力
    System.out.println(count);
  }
}
