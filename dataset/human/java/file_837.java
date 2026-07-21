import java.util.Scanner;
import java.util.Arrays;
class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
    int R = scan.nextInt();
    int rate = 0;
    if (N >= 10) {
      rate = R;
    }
    else{
      int a = 100 * (10 - N);
      rate = R + a;
    }
    System.out.println(rate);
  }
}
