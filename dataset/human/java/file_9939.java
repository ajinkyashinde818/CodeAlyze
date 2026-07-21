import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int X = sc.nextInt();
    long[][] A = new long[N][M];
    long[] C = new long[N];
    int[] check = new int[N];
    for (int i =0; i<N; i++) {
      C[i] = Long.parseLong(sc.next());
      for (int j =0; j<M; j++) {
        A[i][j] = sc.nextInt();
      }
    }
    
    long min = 1200001;
    char[] sp = new char[N+1];
    for (int i = 1; i < Math.pow(2, N); i++) { 
      sp = String.format("%0" + N + "d", Long.parseLong(Integer.toBinaryString(i))).toCharArray();
      long[] Acheck = new long[M+1];
      for (int j =0; j<N; j++) {
        if (sp[j] == '0') {
          continue;
        }
        for (int k = 0; k <M; k++) {
          Acheck[k] += A[j][k];
	    }
      }
	  boolean flg = true;
	  for (int j =0; j <M; j++) {
        if (Acheck[j] < X) {
          flg = false;
        }
      }
      if (flg) {
        long ans = 0;
        for (int j = 0; j <N; j++) {
          if (sp[j] == '1') ans += C[j];
	      }
	    min = Math.min(min, ans);
      }
    }
    if (min == 1200001) min = -1;
	System.out.println(min);
  }
}
