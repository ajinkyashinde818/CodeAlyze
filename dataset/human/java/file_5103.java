import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String S = scan.next();
    int Q = scan.nextInt();
    long[] T = new long[Q];
    long[] F = new long[Q];
    String[] C = new String[Q];

    StringBuffer before = new StringBuffer();
    StringBuffer after = new StringBuffer();
    int reverse = 0;
    for(int i=0; i<Q; i++) {
      T[i] = scan.nextLong();
      if(T[i] == 1) {
        reverse = reverse == 1 ? 0 : 1;
      }
      else {
        F[i] = scan.nextLong();
        C[i] = scan.next();
        if((reverse + F[i]) % 2 == 1) {
          before.append(C[i]);
        }
        else {
          after.append(C[i]);
        }
      }
    }
    scan.close();

    if(reverse == 1) {
      StringBuffer SReverse = new StringBuffer(S);
      System.out.print(after.reverse());
      System.out.print(SReverse.reverse());
      System.out.println(before);
    }
    else {
      System.out.print(before.reverse());
      System.out.print(S);
      System.out.println(after);
    }
  }
}
