import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int bigger = Math.max(A, B);
    int smaller = Math.min(A, B);
    ArrayList<Integer> list = new ArrayList<Integer>();

    for (int i = 1; i <= smaller; i++) {
      if (bigger % i == 0 && smaller % i == 0) {
        list.add(i);
      }
    }
    Collections.sort(list, Collections.reverseOrder());
    System.out.println(list.get(C - 1));
  }
}
