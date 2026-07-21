import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int k = s.nextInt();
    int n = s.nextInt();
    int[] a = new int[n];
    int answer = k;
    for(int i = 0; i < n; i++) {
      a[i] = s.nextInt();
    }
    if(n == 2) {
      answer = a[1]-a[0];
    } else {
      for(int i = 1; i < n; i++) {
        int y = a[i-1]+k-a[i];
        if(answer > y) {
          answer = y;
        }
      }
      int x = a[n-1]-a[0];
      if(answer > x) {
        answer = x;
      }
    }

    System.out.println(answer);
  }
}
