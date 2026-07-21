import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    	int num = sc.nextInt();
    	int score = sc.nextInt();
    	if(num < 10) {
          System.out.println(score + 100 * ( 10 - num));
        } else {
          System.out.println(score);
        }
  }
}
