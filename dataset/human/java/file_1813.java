import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt(); 
    int G = sc.nextInt();
    int[] p = new int[N];
    int[] c = new int[N];
    for (int i = 0; i < N; i++) {
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    int min = Integer.MAX_VALUE;
    for (int i = 0; i < Math.pow(2,N); i++) {
      int count = 0;
      int total = 0;
      int t = -1;
      for (int j = N-1; j >= 0; j--) {
        if((1&i>>j) == 1) {
          count += p[j];
          total += c[j] + p[j]*(j+1)*100;
        } else if (t == -1) {
          t = j;
        }
      }
      if (G > total && t != -1) {
        for (int j = 0; j < p[t]-1; j++) {
          total += (t+1)*100;
          count ++;
          if (total >= G) break;
        }
      }
      if (G > total) continue;
      //System.out.println("i: " + i + " total: " + total + " count: " + count + " min: " + min);
      min = Math.min(min, count);
    }
    System.out.println(min);
  }
}
