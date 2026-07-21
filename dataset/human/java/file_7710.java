import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    long K = scanner.nextLong();
    int[] A = new int[N];
    boolean[] D = new boolean[N];
    for(int i = 0; i < N; i++) {
      A[i] = scanner.nextInt();
      D[i] = false;
    }
    int C = 0;
    do {
      D[C] = true;
      C = A[C] - 1;
    } while(!D[C]);
    int count = 0;
    int start = C;
    do {
      C = A[C] - 1;
      count++;
    } while(C != start);
    C = 0;
    int offset = 0;
    do {
      C = A[C] - 1;
      offset++;
    } while(C != start);
    C = 0;
    long move = K > offset ? ((K - offset) % count) + offset : K;
    for(int i = 0; i < move; i++) C = A[C] - 1;
    System.out.println(C + 1);
  }
}
