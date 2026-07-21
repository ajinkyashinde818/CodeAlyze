import java.util.Scanner;

public class Main { 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int D = sc.nextInt();
    int G = sc.nextInt();
    int[] p = new int[D];
    int[] c = new int[D];
    for (int i =0; i<D; i++) {
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    int min =1001; int count =0; int ans =0;
    int a = 4;
    for (int i =0; i<Math.pow(2,D); i++) {
      String bit = String.format("%" + D + "s", Integer.toBinaryString(i)).replace(' ', '0');
      int N = bit.length();
      for (int j=0; j<N; j++) {
        if (bit.charAt(j) == '1' ) {
          count += p[j] * (j + 1) * 100 + c[j];
          ans += p[j];
        }
      }
      if (count<G) {
        for (int j=N-1; j>=0; j--) {
          if (bit.charAt(j) == '0' ) {
            int l = p[j];
            while (count < G && l > 0) {
              count += (j + 1) * 100;
              ans++;
              l--;
            }
          }
        }
      }
      if (count >= G) {
        min = Math.min(ans,min);
      }
      count =0;
      ans =0;
    }
    System.out.println(min);
  }
}
