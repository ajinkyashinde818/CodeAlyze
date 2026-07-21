import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int D = sc.nextInt();
    int G = sc.nextInt();
    int[] p = new int[D+1];
    int[] c = new int[D+1];
    for (int i = 1; i <= D; i++) {
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    
    int min = Integer.MAX_VALUE;
    int bit = 1 << D;
    for (int i = 0; i < bit; i++) {
      int num = solve(i, p, c, G);
      if (num < min) {
        min = num;
      }
    }
    
    System.out.println(min);
  }
  
  private static int solve(int i, int[] p, int[] c, int G) {

    int maxUnused = c.length - 1;
    int solved = 0;
    int j = 1;
    int score = 0;
    while (i != 0) {
      if (i % 2 == 1) {
        score += (c[j] + p[j] * 100 * j);
        solved += p[j];
      } else {
        maxUnused = j;
      }
      i /= 2;
      j++;
    }
    if (score >= G) {
      return solved;
    }

    for (int a = 1; a < p[maxUnused]; a++) {
      score += 100*maxUnused;
      solved++;
      if (score >= G) {
        return solved;
      }
    }

    return Integer.MAX_VALUE;
  }
}
