import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int A = Integer.parseInt(sc.next());
    int B = Integer.parseInt(sc.next());
    int C = Integer.parseInt(sc.next());

    long ans = 0;
    if(A+B>=C-1) {
      ans = B+C;
    }else  {
      ans = 2*B+A+1;
    }

    System.out.println(ans);
  }
}
