import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String[] input = sc.nextLine().split(" ");
    Integer n = Integer.parseInt(input[0]);
    Integer r = Integer.parseInt(input[1]);
    Integer x = 0;
    if(n < 10) {
      x = r + 100 * (10-n);
    } else {
      x = r;
    }
    System.out.println(x); 
  }
}
