import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long A = sc.nextLong();
    long B = sc.nextLong();
    long C = sc.nextLong();
    long AB = A+B;
    if(A+B >= C){
      System.out.println(B+C);
    }else{
      System.out.println(A + 2 * B + 1);
    }
  }
}
