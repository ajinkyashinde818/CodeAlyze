import java.util.Scanner;

public class Main {
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int R = scanner.nextInt();
    int score = 0;
    if(N >= 10){
      score = R;
    }else{
      score = R + (100 * (10-N));
    }
    System.out.println(score);
  }
}
