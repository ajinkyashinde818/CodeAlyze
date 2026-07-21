import java.util.*;

class Main {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int l[] = new int[100003];
    for (int i = 0; i < n; i++) {
      l[sc.nextInt()]++;
      l[sc.nextInt()+1]--;
    }
    for (int i = 1; i < 100003; i++)
      l[i] += l[i-1];
    int max = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (i - 1 <= l[i]) {
        max = i - 1;
      }
    }
    System.out.println(max);
  }
}
