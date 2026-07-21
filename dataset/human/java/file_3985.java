import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
    scan.nextLine();
    int[] AArray = new int[N];
    int[] BArray = new int[N];
    int[] CArray = new int[N - 1];
    for (int i = 0; i < N; i++) {
      AArray[i] = scan.nextInt();
    }
    for (int i = 0; i < N; i++) {
      BArray[i] = scan.nextInt();
    }
    for (int i = 0; i < N - 1; i++) {
      CArray[i] = scan.nextInt();
    }
    int result = 0;
    int tmp = -1;
    for (int i = 0; i < N; i++) {
      int atmp = AArray[i];
      result += BArray[atmp - 1];
      if (atmp - tmp == 1) {
        result += CArray[tmp - 1];
      }
      tmp = atmp;
    }

    System.out.println(result);

  }

}
